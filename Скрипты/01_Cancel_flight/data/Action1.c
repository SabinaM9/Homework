Action1()
{

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(5);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t179.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(37);

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t180.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=13-0-MR", ENDITEM, 
		"Name=flightID", "Value=242-1-OD", ENDITEM, 
		"Name=flightID", "Value=45-2-JJ", ENDITEM, 
		"Name=flightID", "Value=205643376-3088-CF", ENDITEM, 
		"Name=flightID", "Value=4458-3875-\r\n", ENDITEM, 
		"Name=flightID", "Value=4458-4645-\r\n", ENDITEM, 
		"Name=removeAllFlights.x", "Value=63", ENDITEM, 
		"Name=removeAllFlights.y", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		LAST);

	return 0;
}