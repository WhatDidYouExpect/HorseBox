function OnClientExecCmd(client,cmd)
{
	PrintToServer(client.tostring()+": "+cmd+"\n");
	if(startswith(cmd,"DisplayHint "))
	{
		SendKeyHintToClient(client,cmd.slice(12));
	}
	else if(startswith(cmd,"GetPosition"))
	{
		local pos = EntityGetPosition(client);
		PrintToServer(pos[0].tostring()+" "+pos[1].tostring()+" "+pos[2].tostring()+"\n");
	}
}

function OnClientSpawned(client)
{
	PrintToServer(client.tostring()+"\n")
	SendKeyHintToClient(client,"BRUBURBURU");
	GiveNamedItem(client,"weapon_ar2",0);
}