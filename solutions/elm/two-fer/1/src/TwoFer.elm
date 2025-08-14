module TwoFer exposing (twoFer)


twoFer : Maybe String -> String
twoFer name =
    let
        outName =
            case name of
                Just output ->
                    output

                Nothing ->
                    "you"
    in
    "One for " ++ outName ++ ", one for me."
