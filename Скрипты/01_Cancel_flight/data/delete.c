delete()
{

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_concurrent_start(NULL);

	web_url("home.gif", 
		"URL=http://localhost:1080/WebTours/images/home.gif", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t13.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_url("cancelallreservations.gif", 
		"URL=http://localhost:1080/WebTours/images/cancelallreservations.gif", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t14.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_url("cancelreservation.gif", 
		"URL=http://localhost:1080/WebTours/images/cancelreservation.gif", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t15.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(34);

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=61157509-827-SM", ENDITEM, 
		"Name=flightID", "Value=61157509-1597-SM", ENDITEM, 
		"Name=flightID", "Value=61157509-2366-SM", ENDITEM, 
		"Name=flightID", "Value=61157509-3135-SM", ENDITEM, 
		"Name=flightID", "Value=0-38-\r\n", ENDITEM, 
		"Name=flightID", "Value=61155975-4641-SM", ENDITEM, 
		"Name=removeFlights.x", "Value=73", ENDITEM, 
		"Name=removeFlights.y", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		LAST);

	return 0;
}