function OnClientExecCmd(client,cmd)
{
	PrintToServer(client.tostring()+": "+cmd+"\n");
	if(startswith(cmd,"DisplayHint "))
	{
		SendKeyHintToClient(client,cmd.slice(12));
	}
}