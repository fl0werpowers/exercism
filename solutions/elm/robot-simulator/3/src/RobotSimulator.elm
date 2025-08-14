module RobotSimulator exposing
    ( Bearing(..)
    , Robot
    , advance
    , defaultRobot
    , simulate
    , turnLeft
    , turnRight
    )


type Bearing
    = North
    | East
    | South
    | West


type alias Robot =
    { bearing : Bearing
    , coordinates : { x : Int, y : Int }
    }


defaultRobot : Robot
defaultRobot =
    { bearing = North
    , coordinates = { x = 0, y = 0 }
    }


turnRight : Robot -> Robot
turnRight robot =
    { robot
        | bearing =
            case robot.bearing of
                North ->
                    East

                East ->
                    South

                South ->
                    West

                West ->
                    North
    }


turnLeft : Robot -> Robot
turnLeft robot =
    { robot
        | bearing =
            case robot.bearing of
                North ->
                    West

                East ->
                    North

                South ->
                    East

                West ->
                    South
    }


advance : Robot -> Robot
advance { bearing, coordinates } =
    case bearing of
        North ->
            Robot bearing { coordinates | y = coordinates.y + 1 }

        East ->
            Robot bearing { coordinates | x = coordinates.x + 1 }

        South ->
            Robot bearing { coordinates | y = coordinates.y - 1 }

        West ->
            Robot bearing { coordinates | x = coordinates.x - 1 }


simulate : String -> Robot -> Robot
simulate directions robot =
    String.toList directions |> List.foldl robotAction robot


robotAction : Char -> Robot -> Robot
robotAction action robot =
    case action of
        'R' ->
            turnRight robot

        'L' ->
            turnLeft robot

        'A' ->
            advance robot

        _ ->
            robot
