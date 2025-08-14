module SumOfMultiples exposing (..)


sumOfMultiples : List Int -> Int -> Int
sumOfMultiples divisors limit =
    List.sum <|
        combineMultLists <|
            List.map (multList limit) divisors


multList limit num =
    multListHelper limit num num


multListHelper : Int -> Int -> Int -> List Int
multListHelper limit multiplier num =
    if num + multiplier >= limit then
        [ num ]

    else
        num :: multListHelper limit multiplier (num + multiplier)


combineMultLists : List (List Int) -> List Int
combineMultLists =
    List.concat >> unique


unique : List a -> List a
unique list =
    let
        incUnique : a -> List a -> List a
        incUnique elem lst =
            if List.member elem lst then
                lst

            else
                elem :: lst
    in
    List.foldr incUnique [] list
