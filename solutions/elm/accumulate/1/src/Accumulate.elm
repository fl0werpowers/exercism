module Accumulate exposing (accumulate)


accumulate : (a -> b) -> List a -> List b
accumulate func input =
    case input of
        [] ->
            []

        first :: rest ->
            func first :: accumulate func rest
