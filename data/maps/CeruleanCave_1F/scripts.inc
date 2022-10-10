CeruleanCave_1F_MapScripts::
	.byte 0

CeruleanCave_1F_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE, 1
	release
	end

CeruleanCave_1F_EventScript_ItemNugget::
	finditem ITEM_NUGGET, 1
	release
	end

CeruleanCave_1F_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR, 1
	release
	end
