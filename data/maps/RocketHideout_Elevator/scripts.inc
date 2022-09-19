RocketHideout_Elevator_MapScripts::
	.byte 0

RocketHideout_Elevator_EventScript_FloorSelect::
	lock
	faceplayer
	checkitem ITEM_LIFT_KEY
	goto_if_eq VAR_RESULT, FALSE, RocketHideout_Elevator_NeedKey
	setvar VAR_0x8004, 0
	call_if_unset FLAG_TEMP_2, RocketHideout_Elevator_EventScript_SetFloor
	copyvar VAR_0x8005, VAR_DEPT_STORE_FLOOR
	special ShowDeptStoreElevatorFloorSelect
	message Text_WhichFloorWillYouPick
	waitmessage
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetDeptStoreDefaultFloorChoice
	switch VAR_RESULT
	case 0, RocketHideout_Elevator_EventScript_FloorSelectFromB1F
	case 1, RocketHideout_Elevator_EventScript_FloorSelectFromB2F
	case 2, RocketHideout_Elevator_EventScript_FloorSelectFromB4F
	end

Text_WhichFloorWillYouPick::
	.string "Which floor will you pick?$"

RocketHideout_Elevator_NeedKey::
	msgbox RocketHideout_Elevator_Text_AppearsToNeedAKey, MSGBOX_AUTOCLOSE
	release
	end

RocketHideout_Elevator_Text_AppearsToNeedAKey::
    .string "It appears to need a key.$"

@ Below scripts ensure the cursor for floor select always starts on the current floor
RocketHideout_Elevator_EventScript_FloorSelectFromB1F::
	multichoicedefault 0, 0, MULTI_HIDEOUT_FLOORS, 0, FALSE
	goto RocketHideout_Elevator_EventScript_ChooseFloor
	end

RocketHideout_Elevator_EventScript_FloorSelectFromB2F::
	multichoicedefault 0, 0, MULTI_HIDEOUT_FLOORS, 1, FALSE
	goto RocketHideout_Elevator_EventScript_ChooseFloor
	end

RocketHideout_Elevator_EventScript_FloorSelectFromB4F::
	multichoicedefault 0, 0, MULTI_HIDEOUT_FLOORS, 2, FALSE
	goto RocketHideout_Elevator_EventScript_ChooseFloor
	end

RocketHideout_Elevator_EventScript_ChooseFloor::
	switch VAR_RESULT
	case 0, RocketHideout_Elevator_EventScript_B1F
	case 1, RocketHideout_Elevator_EventScript_B2F
	case 2, RocketHideout_Elevator_EventScript_B4F
	case 3, RocketHideout_Elevator_EventScript_ExitFloorSelect
	case MULTI_B_PRESSED, RocketHideout_Elevator_EventScript_ExitFloorSelect
	end

RocketHideout_Elevator_EventScript_B1F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_B1F
	setdynamicwarp MAP_ROCKET_HIDEOUT_B1F, 24, 25
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B1F, RocketHideout_Elevator_EventScript_ExitFloorSelect
	call RocketHideout_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B1F
	goto RocketHideout_Elevator_EventScript_ExitFloorSelect
	end

RocketHideout_Elevator_EventScript_B2F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_B2F
	setdynamicwarp MAP_ROCKET_HIDEOUT_B2F, 28, 16
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B2F, RocketHideout_Elevator_EventScript_ExitFloorSelect
	call RocketHideout_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B2F
	goto RocketHideout_Elevator_EventScript_ExitFloorSelect
	end

RocketHideout_Elevator_EventScript_B4F::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_B4F
	setdynamicwarp MAP_ROCKET_HIDEOUT_B4F, 20, 23
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B4F, RocketHideout_Elevator_EventScript_ExitFloorSelect
	call RocketHideout_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B4F
	goto RocketHideout_Elevator_EventScript_ExitFloorSelect
	end

RocketHideout_Elevator_EventScript_ExitFloorSelect::
	special CloseDeptStoreElevatorWindow
	release
	end

RocketHideout_Elevator_EventScript_MoveElevator::
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

RocketHideout_Elevator_EventScript_SetFloor::
	special SetDeptStoreFloor
	return
