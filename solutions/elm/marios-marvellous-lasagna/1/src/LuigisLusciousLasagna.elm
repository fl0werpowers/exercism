module LuigisLusciousLasagna exposing (remainingTimeInMinutes)

-- TODO: define the remainingTimeInMinutes function
-- let
--     expectedMinutesInOven = 40
--     preparationTimeInMinutes layers = layers * 2
--     -- elapsedTimeInMinutes minutesInOven = preparationTimeInMinutes + minutesInOven
--     remainingTimeInMinutes = expectedMinutesInOven
--     -- remainingTimeInMinutes layers minutesInOven = expectedMinutesInOven - preparationTimeInMinutes
-- in remainingTimeInMinutes


remainingTimeInMinutes : number -> number -> number
remainingTimeInMinutes layers minutesInOven =
    let
        expectedMinutesInOven =
            40

        preparationTimeInMinutes =
            layers * 2
    in
    preparationTimeInMinutes + expectedMinutesInOven - minutesInOven
