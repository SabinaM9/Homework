Action2()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

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

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t136.inf", 
		"Mode=HTML", 
		LAST);

	web_url("extension_4_21_0_0.crx", 
		"URL=https://clients2.googleusercontent.com/crx/blobs/QwAAAHF3InbmK-wFIemaY3I3BCO7Rlu1Xl_g6NfcjDF5BmhV8O-I6g5Iac-W8jJy-HRPBqobLybp5txveSdqm4QQlktAum-sdWDEMaB7HyYckS_5AMZSmuUYmL6cKig5tSqGI7yZpr6zsJv5gA/extension_4_21_0_0.crx", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/x-chrome-extension", 
		"Referer=", 
		"Snapshot=t137.inf", 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(12);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t138.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=129636.680680437zzziVizpHzcftAAAQpVcAfHf", ENDITEM, 
		"Name=username", "Value=VUser11", ENDITEM, 
		"Name=password", "Value=VUser11", ENDITEM, 
		"Name=login.x", "Value=50", ENDITEM, 
		"Name=login.y", "Value=14", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(207);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t139.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}