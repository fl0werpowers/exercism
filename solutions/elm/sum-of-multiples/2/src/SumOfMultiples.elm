module SumOfMultiples exposing (sumOfMultiples)

import Set


sumOfMultiples : List Int -> Int -> Int
sumOfMultiples divisors limit =
    List.map (multList limit) divisors
        |> List.concat
        |> Set.fromList
        |> Set.foldl (+) 0


multList : Int -> Int -> List Int
multList limit num =
    multListHelper limit num num


multListHelper : Int -> Int -> Int -> List Int
multListHelper limit multiplier num =
    if num + multiplier >= limit then
        [ num ]

    else
        num :: multListHelper limit multiplier (num + multiplier)
