SilphCo_Elevator_MapScripts::
	.byte 0

SilphCo_Elevator_EventScript_FloorSelect::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	call_if_unset FLAG_TEMP_2, SilphCo_Elevator_EventScript_SetFloor
	copyvar VAR_0x8005, VAR_DEPT_STORE_FLOOR
	special ShowDeptStoreElevatorFloorSelect
	message Text_WhichFloorWillYouPick
	waitmessage
	multichoicegrid 0, 0, MULTI_SILPH_FLOORS, 2, FALSE
	switch VAR_RESULT
	case 0, SilphCo_Elevator_EventScript_10F
	case 1, SilphCo_Elevator_EventScript_11F
	case 2, SilphCo_Elevator_EventScript_8F
	case 3, SilphCo_Elevator_EventScript_9F
	case 4, SilphCo_Elevator_EventScript_6F
	case 5, SilphCo_Elevator_EventScript_7F
	case 6, SilphCo_Elevator_EventScript_4F
	case 7, SilphCo_Elevator_EventScript_5F
	case 8, SilphCo_Elevator_EventScript_2F
	case 9, SilphCo_Elevator_EventScript_3F
	case 10, SilphCo_Elevator_EventScript_1F
	case 11 SilphCo_Elevator_EventScript_ExitFloorSelect
	case MULTI_B_PRESSED, SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_11F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_11F
	setdynamicwarp MAP_SILPH_CO_11F, 13, 3
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_11F, SilphCo_Elevator_EventScript_ExitFloorSelect
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_11F
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_10F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_10F
	setdynamicwarp MAP_SILPH_CO_10F, 13, 3
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_10F, SilphCo_Elevator_EventScript_ExitFloorSelect
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_10F
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_9F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_9F
	setdynamicwarp MAP_SILPH_CO_9F, 24, 3
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_9F, SilphCo_Elevator_EventScript_ExitFloorSelect
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_9F
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_8F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_8F
	setdynamicwarp MAP_SILPH_CO_8F, 22, 3
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_8F, SilphCo_Elevator_EventScript_ExitFloorSelect
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_8F
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_7F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_7F
	setdynamicwarp MAP_SILPH_CO_7F, 23, 3
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_7F, SilphCo_Elevator_EventScript_ExitFloorSelect
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_7F
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_6F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_6F
	setdynamicwarp MAP_SILPH_CO_6F, 20, 3
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_6F, SilphCo_Elevator_EventScript_ExitFloorSelect
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_6F
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_5F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_5F
	setdynamicwarp MAP_SILPH_CO_5F, 22, 3
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F, SilphCo_Elevator_EventScript_ExitFloorSelect
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_4F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_4F
	setdynamicwarp MAP_SILPH_CO_4F, 22, 3
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F, SilphCo_Elevator_EventScript_ExitFloorSelect
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_3F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_3F
	setdynamicwarp MAP_SILPH_CO_3F, 22, 3
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F, SilphCo_Elevator_EventScript_ExitFloorSelect
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_2F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_2F
	setdynamicwarp MAP_SILPH_CO_2F, 22, 3
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F, SilphCo_Elevator_EventScript_ExitFloorSelect
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_1F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_1F
	setdynamicwarp MAP_SILPH_CO_4F, 22, 3
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F, SilphCo_Elevator_EventScript_ExitFloorSelect
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_ExitFloorSelect::
	special CloseDeptStoreElevatorWindow
	release
	end

SilphCo_Elevator_EventScript_MoveElevator::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	special CloseDeptStoreElevatorWindow
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	waitse
	special MoveElevator
	waitstate
	setflag FLAG_TEMP_2
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

SilphCo_Elevator_EventScript_SetFloor::
	special SetDeptStoreFloor
	return
