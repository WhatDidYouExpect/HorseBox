function OnClientExecCmd(client,cmd)
{
	PrintToServer(client.tostring()+": "+cmd+"\n");
	if(startswith(cmd,"DisplayHint "))
	{
		SendKeyHintToClient(client,cmd.slice(12));
	}
}

function OnClientSpawned(client)
{
	PrintToServer(client.tostring()+"\n")
	SendKeyHintToClient(client,"BRUBURBURU");
	GiveNamedItem(client,"weapon_ar2",0);
}