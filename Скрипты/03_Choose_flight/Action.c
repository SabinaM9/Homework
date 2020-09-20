Action()
{
	lr_start_transaction("03_Choose_flight");

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

//input type="hidden" name="userSession" value="129622.008991495zzzHtDcpAiHftAAAtpfQcfcf"/>
	web_reg_save_param("userSession",
		"LB=input type=\"hidden\" name\=\"userSession\" value\=\"",
		"RB=\"\/\>",
		LAST);

	//Проверка транзакции connection
	web_reg_find("Text=A Session ID has been created and loaded into a cookie called MSO.",
		LAST);

	lr_start_transaction("connection");

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("connection", LR_AUTO);

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	//Проверка транзакции login
	web_reg_find("Text=Welcome, <b>{login}</b>, to the Web Tours reservation pages",
		LAST,
		"Text=User password was correct - added a cookie with the user's default",
		LAST);

	lr_start_transaction("login");

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=52", ENDITEM,
		"Name=login.y", "Value=1", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("login", LR_AUTO);

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(6);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(22);

	//Проверка транзакции insert_info_for_ticket_search
	web_reg_find("Text=Flight departing from <B>{departure}</B> to <B>{arrival}</B> on <B>{departDate}</B>",
		LAST);
	
	//Для выбора рандомного рейса
	web_reg_save_param_attrib(
		"ParamName=outboundFlight_id",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Ordinal={randIndex}",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);
		
	web_reg_save_param("flight_id",
		"LB=name=\"outboundFlight\" value=\"",
		"RB=;",
		"Ord={randIndex}",
		LAST);

	web_reg_save_param("flight_time",
		"LB=<td align=\"center\">",
		"RB=m<td align=\"center\">$ ",
		"Ord={randIndex}",
		LAST);

	lr_start_transaction("insert_info_for_ticket_search");

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={departure}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrival}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value={numPassengers}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=findFlights.x", "Value=39", ENDITEM, 
		"Name=findFlights.y", "Value=17", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("insert_info_for_ticket_search", LR_AUTO);

	lr_think_time(28);

	//Проверка транзакции choose_the_flight
	web_reg_find("Text=Flight Reservation",
		LAST,
		"Text=A {seatType} Class ticket",
		LAST,
		"Text=from {departure} to {arrival}.",
		LAST);

	lr_start_transaction("choose_the_flight");

	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight_id}", ENDITEM,
		"Name=numPassengers", "Value={numPassengers}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=reserveFlights.x", "Value=52", ENDITEM,
		"Name=reserveFlights.y", "Value=4", ENDITEM,
		LAST);
	
	lr_end_transaction("choose_the_flight", LR_AUTO);

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(27);
	
	//Проверка транзакции view_itinerary
	web_reg_find("Text=Flight Transaction Summary",
	             LAST,
	             "Text=Flights List",
	             LAST);
	
	lr_start_transaction("view_itinerary");

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("view_itinerary", LR_AUTO);
	
	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(5);

	//Проверка транзакции logout
	web_reg_find("Text=A Session ID has been created and loaded into a cookie called MSO.",
		LAST);
	
	lr_start_transaction("logout");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout", LR_AUTO);
	
	lr_end_transaction("03_Choose_flight", LR_AUTO);

	return 0;
}