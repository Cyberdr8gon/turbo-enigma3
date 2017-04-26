# WHO: Sam Bateman, Kylee Bennett, Tanay Choudhary, Sheena Hann

# TITLE: TurboEnigma3

# VISION: Create a fun, simple dungeon crawler

# AUTOMATED TESTS:

![[test proof image]](testProof.png)



# USER ACCEPTANCE TESTS

================================================================
## Move hero through dungeon and navigate with arrow keys

## Description
Navigate a randomly generated dungeon with a hero controlled by arrow keys, moving through doors, rooms and hallways. 

## Pre-conditions
Must have platform layer completed. Required randomly generated maps and a entity system.

## Test-steps
spawn your hero and find the upstairs.

## Expected result
Find stairs through elaborate maze 

## Actual result
Found stairs through elaborate maze

## Status (Pass/Fail)
Pass

## Notes

## Post-conditions
Expand entity system to hold enemies and items

=================================================================

================================================================
## Pick up item

## Description
find a randomly placed item and pick up and use by hero against other entities

## Pre-conditions
other entities have been implemented, items have been implemented, populating the map has been implimented

## Test-steps
find randomly placed item (can cheat sheet in debug mode for x/y coords)

## Expected result
Find randomly placed item

## Actual result
No items spawned

## Status (Pass/Fail)
Fail

## Notes

## Post-conditions

=================================================================

================================================================
## Fight and kill enemy

## Description
Find and kill enemy

## Pre-conditions
implemented populate map, implimented skill system, implemented entity system

## Test-steps
Find enemy and fight/kill him

## Expected result
enemy is cleaned up and drops items on death

## Actual result
no enemies on map

## Status (Pass/Fail)
Fail

## Notes

## Post-conditions

=================================================================


