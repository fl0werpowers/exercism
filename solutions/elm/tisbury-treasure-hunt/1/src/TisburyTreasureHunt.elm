module TisburyTreasureHunt exposing (..)

-- Consider defining a type alias for TreasureLocation,
-- Treasure, PlaceLocation and Place,
-- and using them in the function type annotations


placeLocationToTreasureLocation : ( Char, Int ) -> ( Int, Char )
placeLocationToTreasureLocation placeLocation =
    let
        ( place, location ) =
            placeLocation
    in
    ( location, place )


treasureLocationMatchesPlaceLocation : ( Char, Int ) -> ( Int, Char ) -> Bool
treasureLocationMatchesPlaceLocation placeLocation treasureLocation =
    placeLocationToTreasureLocation placeLocation == treasureLocation


countPlaceTreasures : ( String, ( Char, Int ) ) -> List ( String, ( Int, Char ) ) -> Int
countPlaceTreasures place treasures =
    let
        placeTreasureLoc =
            Tuple.second place |> placeLocationToTreasureLocation
    in
    List.filter (\tuple -> Tuple.second tuple == placeTreasureLoc) treasures
        |> List.length


type alias TreasureLocation =
    ( Int, Char )


type alias PlaceLocation =
    ( Char, Int )


specialCaseSwapPossible : ( String, TreasureLocation ) -> ( String, PlaceLocation ) -> ( String, TreasureLocation ) -> Bool
specialCaseSwapPossible ( foundTreasure, _ ) ( place, _ ) ( desiredTreasure, _ ) =
    case ( foundTreasure, place, desiredTreasure ) of
        ( "Brass Spyglass", "Abandoned Lighthouse", _ ) ->
            True

        ( "Amethyst Octopus", "Stormy Breakwater", "Crystal Crab" ) ->
            True

        ( "Amethyst Octopus", "Stormy Breakwater", "Glass Starfish" ) ->
            True

        ( "Vintage Pirate Hat", "Harbor Managers Office", "Model Ship in Large Bottle" ) ->
            True

        ( "Vintage Pirate Hat", "Harbor Managers Office", "Antique Glass Fishnet Float" ) ->
            True

        _ ->
            False
