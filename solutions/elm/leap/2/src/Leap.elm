module Leap exposing (isLeapYear)


isLeapYear : Int -> Bool
isLeapYear year =
    divisibleByNum 4 year
        && (if divisibleByNum 100 year then
                divisibleByNum 400 year

            else
                True
           )


divisibleByNum : Int -> Int -> Bool
divisibleByNum num year =
    modBy num year == 0
