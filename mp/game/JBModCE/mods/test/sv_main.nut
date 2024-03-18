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
	local ent = FindEntityByName("SEObspwn1",-1,-1);
	if(ent == null)
	{
		PrintToServer("Couldnt find ent\n");
		return;
	}
	PrintToServer("theent: "+ent.tostring()+"\n");
	//EntityFireInputBool(ent,"ForceSpawn",-1,-1,true);
}

function OnTakeDamage(client, damage, attacker, weapon, type)
{
	PrintToServer(client.tostring()+" received "+damage.tostring()+" damage.\n");
}