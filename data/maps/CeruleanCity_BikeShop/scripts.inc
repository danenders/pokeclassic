CeruleanCity_BikeShop_MapScripts::
	.byte 0

CeruleanCity_BikeShop_EventScript_Bicycle::
	msgbox CeruleanCity_BikeShop_Text_ShinyNewBicycle, MSGBOX_SIGN
	end

CeruleanCity_BikeShop_Text_ShinyNewBicycle::
    .string "A shiny new Bicycle!$"

CeruleanCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle
	goto_if_set FLAG_GOT_BIKE_VOUCHER, CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher
	showmoneybox 0, 0
	message CeruleanCity_BikeShop_Text_WelcomeToBikeShop
	waitmessage
	multichoice 14, 0, MULTI_BIKE, FALSE
	switch VAR_RESULT
	case 0, CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle
	case 1, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

CeruleanCity_BikeShop_Text_WelcomeToBikeShop::
    .string "Hi!\n"
    .string "Welcome to our Bike Shop.\p"
    .string "Have we got just the Bike for\n"
    .string "you!$"

@ The Bicycle price / players money is never actually checked
CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle::
	msgbox CeruleanCity_BikeShop_Text_SorryYouCantAffordIt
	goto CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

CeruleanCity_BikeShop_Text_SorryYouCantAffordIt::
    .string "Sorry!\n"
    .string "You can't afford it!$"

CeruleanCity_BikeShop_EventScript_ClerkGoodbye::
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain
	hidemoneybox
	release
	end

CeruleanCity_BikeShop_Text_ThankYouComeAgain::
    .string "Thank you!\n"
    .string "Come back again sometime!$"

CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle::
	msgbox CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle::
    .string "How do you like your new Bicycle?\n"
    .string "Do you like how it rides?\p"
    .string "You can take it out on Cycling\n"
    .string "Road and even into caves!$"

CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher::
	checkitem ITEM_BIKE_VOUCHER, 1
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_BikeShop_EventScript_BringBikeVoucher
	msgbox CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle
	waitmessage
	waitfanfare
	closemessage
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_MACH_BIKE, 1
	removeitem ITEM_BIKE_VOUCHER
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo::
    .string "Oh, that's…\p"
    .string "A Bike Voucher!\p"
    .string "Okay!\n"
    .string "Here you go!$"

CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle::
    .string "{PLAYER} exchanged the\n"
    .string "Bike Voucher for a Bicycle.$"

CeruleanCity_BikeShop_EventScript_BringBikeVoucher::
	msgbox CeruleanCity_BikeShop_Text_MakeRoomForBicycle, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BikeShop_Text_MakeRoomForBicycle::
    .string "What's that, kid?\p"
    .string "You can't just tell me you have\n"
    .string "a Bike Voucher, you gotta bring\l"
    .string "it to me!$"

CeruleanCity_BikeShop_EventScript_Woman::
	msgbox CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe, MSGBOX_NPC
	end

CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe::
    .string "A plain city bike is good enough\n"
    .string "for me.\p"
    .string "I don't need to do any tricks.\p"
    .string "After all, you can't do a wheelie\n"
    .string "when you have a shopping basket!$"

CeruleanCity_BikeShop_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, CeruleanCity_BikeShop_EventScript_YoungsterHaveBike
	msgbox CeruleanCity_BikeShop_Text_BikesCoolButExpensive
	release
	end

CeruleanCity_BikeShop_Text_BikesCoolButExpensive::
    .string "These bikes are cool, but they're\n"
    .string "way expensive!$"

CeruleanCity_BikeShop_EventScript_YoungsterHaveBike::
	msgbox CeruleanCity_BikeShop_Text_WowYourBikeIsCool
	release
	end
	
CeruleanCity_BikeShop_Text_WowYourBikeIsCool::
    .string "Wow.\n"
    .string "Your BIKE is really cool!$"



