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
advance robot =
    { robot
        | coordinates =
            case robot.bearing of
                North ->
                    { x = robot.coordinates.x, y = robot.coordinates.y + 1 }

                East ->
                    { x = robot.coordinates.x + 1, y = robot.coordinates.y }

                South ->
                    { x = robot.coordinates.x, y = robot.coordinates.y - 1 }

                West ->
                    { x = robot.coordinates.x - 1, y = robot.coordinates.y }
    }


simulate : String -> Robot -> Robot
simulate directions robot =
    String.toList directions |> simulateRobotList robot


simulateRobotList : Robot -> List Char -> Robot
simulateRobotList robot directions =
    case directions of
        [] ->
            robot

        first :: rest ->
            simulateRobotList (robotAction first robot) rest


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
