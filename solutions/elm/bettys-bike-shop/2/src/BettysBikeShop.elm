module BettysBikeShop exposing (penceToPounds, poundsToString)


penceToPounds : Int -> Float
penceToPounds pence =
    toFloat pence / 100


poundsToString : Float -> String
poundsToString pounds =
    if remainderBy 10 (round (pounds * 100)) == 0 && not (toFloat (floor pounds) == pounds) then
        "£"
            ++ String.fromFloat pounds
            ++ "0"

    else if toFloat (floor pounds) == pounds then
        "£" ++ String.fromFloat pounds ++ ".00"

    else
        "£" ++ String.fromFloat pounds
