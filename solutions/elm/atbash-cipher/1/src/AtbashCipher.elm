module AtbashCipher exposing (decode, encode)

import Json.Decode exposing (list)
import Regex



-- TODO: Write regex for spaces and punctuation, filter string accordingly
-- TODO: Split characters in encoding into chunks of 5, remove chunks in decoding


isLetter : Char -> Bool
isLetter c =
    Regex.contains (Maybe.withDefault Regex.never (Regex.fromString "[a-z]")) (String.fromChar c)


isWhiteSpace : Char -> Bool
isWhiteSpace c =
    Regex.contains (Maybe.withDefault Regex.never (Regex.fromString "[\\s]")) (String.fromChar c)


isPunctuation : Char -> Bool
isPunctuation c =
    not (Regex.contains (Maybe.withDefault Regex.never (Regex.fromString "[\\sa-zA-Z0-9]")) (String.fromChar c))


replaceLetters : Char -> Char
replaceLetters c =
    Char.toCode c |> (-) (Char.toCode 'z') |> (+) (Char.toCode 'a') |> Char.fromCode


partitionCharList : List Char -> List (List Char)
partitionCharList list =
    if List.length list < 5 then
        [ list ]

    else
        List.append [ List.take 5 list ] (partitionCharList (List.drop 5 list))


encode : String -> String
encode plain =
    String.toLower plain
        |> String.toList
        |> List.filter (\c -> not (isWhiteSpace c) && not (isPunctuation c))
        |> List.map
            (\c ->
                if isLetter c then
                    replaceLetters c

                else
                    c
            )
        |> partitionCharList
        |> List.map String.fromList
        |> String.join " "
        |> String.trim


decode : String -> String
decode cipher =
    String.toLower cipher
        |> String.toList
        |> List.map
            (\c ->
                if isLetter c then
                    replaceLetters c

                else
                    c
            )
        |> List.filter (\c -> c /= ' ')
        |> String.fromList
