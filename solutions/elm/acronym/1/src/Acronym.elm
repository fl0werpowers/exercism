module Acronym exposing (abbreviate)

import Regex


pattern : String
pattern =
    "\\W"


maybeRegex : Maybe Regex.Regex
maybeRegex =
    Regex.fromString pattern


regex : Regex.Regex
regex =
    Maybe.withDefault Regex.never maybeRegex


abbreviate : String -> String
abbreviate phrase =
    Regex.split regex phrase
        |> List.map (String.slice 0 1)
        |> List.map String.toUpper
        |> List.foldr (++) ""
