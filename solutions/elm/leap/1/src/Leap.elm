module Leap exposing (..)


isLeapYear : Int -> Bool
isLeapYear year =
    divisibleByNum 4 year && leapYearException year


divisibleByNum : Int -> Int -> Bool
divisibleByNum num year =
    modBy num year == 0


leapYearException : Int -> Bool
leapYearException year =
    if divisibleByNum 100 year then
        if divisibleByNum 400 year then
            True

        else
            False

    else
        True
