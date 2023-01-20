BattleTower_Elevator_MapScripts::
	.byte 0

BattleTower_Elevator_EventScript_FloorSelect::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	call_if_unset FLAG_TEMP_2, BattleTower_Elevator_EventScript_SetFloor
	copyvar VAR_0x8005, VAR_DEPT_STORE_FLOOR
	special ShowDeptStoreElevatorFloorSelect
	message gText_WhichFloorWouldYouLike
	waitmessage
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetDeptStoreDefaultFloorChoice
	switch VAR_RESULT
	case 0, BattleTower_Elevator_EventScript_ChooseFloorFrom3rd
	case 1, BattleTower_Elevator_EventScript_ChooseFloorFrom2nd
	case 2, BattleTower_Elevator_EventScript_ChooseFloorFrom1st
	case 3, BattleTower_Elevator_EventScript_ChooseFloorFromBasement
	end

@ Below scripts ensure the cursor for floor select always starts on the current floor

BattleTower_Elevator_EventScript_ChooseFloorFrom3rd::
	multichoicedefault 0, 0, MULTI_FRONTIER_FLOORS, 0, FALSE
	goto BattleTower_Elevator_EventScript_ChooseFloor
	end

BattleTower_Elevator_EventScript_ChooseFloorFrom2nd::
	multichoicedefault 0, 0, MULTI_FRONTIER_FLOORS, 1, FALSE
	goto BattleTower_Elevator_EventScript_ChooseFloor
	end

BattleTower_Elevator_EventScript_ChooseFloorFrom1st::
	multichoicedefault 0, 0, MULTI_FRONTIER_FLOORS, 2, FALSE
	goto BattleTower_Elevator_EventScript_ChooseFloor
	end

BattleTower_Elevator_EventScript_ChooseFloorFromBasement::
	multichoicedefault 0, 0, MULTI_FRONTIER_FLOORS, 3, FALSE
	goto BattleTower_Elevator_EventScript_ChooseFloor
	end

BattleTower_Elevator_EventScript_ChooseFloor::
	switch VAR_RESULT
	case 0, BattleTower_Elevator_EventScript_3rdFloor
	case 1, BattleTower_Elevator_EventScript_2ndFloor
	case 2, BattleTower_Elevator_EventScript_1stFloor
	case 3, BattleTower_Elevator_EventScript_Basement
	case 4, BattleTower_Elevator_EventScript_ExitFloorSelect
	case MULTI_B_PRESSED, BattleTower_Elevator_EventScript_ExitFloorSelect
	end

BattleTower_Elevator_EventScript_1stFloor::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_1F
	setdynamicwarp MAP_BATTLE_TOWER_ENTRANCE, 21, 9
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F, BattleTower_Elevator_EventScript_ExitFloorSelect
	call BattleTower_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F
	goto BattleTower_Elevator_EventScript_ExitFloorSelect
	end

BattleTower_Elevator_EventScript_2ndFloor::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_2F
	setdynamicwarp MAP_BATTLE_TOWER_2F_SHOP, 22, 1
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F, BattleTower_Elevator_EventScript_ExitFloorSelect
	call BattleTower_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F
	goto BattleTower_Elevator_EventScript_ExitFloorSelect
	end

BattleTower_Elevator_EventScript_3rdFloor::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_3F
	setdynamicwarp MAP_BATTLE_TOWER_3F_LOUNGE, 22, 1
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F, BattleTower_Elevator_EventScript_ExitFloorSelect
	call BattleTower_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F
	goto BattleTower_Elevator_EventScript_ExitFloorSelect
	end

BattleTower_Elevator_EventScript_Basement::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_B1F
	setdynamicwarp MAP_BATTLE_TOWER_BASEMENT, 23, 1
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B1F, BattleTower_Elevator_EventScript_ExitFloorSelect
	call BattleTower_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B1F
	goto BattleTower_Elevator_EventScript_ExitFloorSelect
	end

BattleTower_Elevator_EventScript_ExitFloorSelect::
	special CloseDeptStoreElevatorWindow
	release
	end

BattleTower_Elevator_EventScript_MoveElevator::
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

BattleTower_Elevator_EventScript_SetFloor::
	special SetDeptStoreFloor
	return
