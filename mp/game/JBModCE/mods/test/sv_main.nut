function OnClientExecCmd(client,cmd)
{
	if(startswith(cmd,"DisplayHint "))
	{
		SendKeyHintToClient(client,cmd.slice(12));
	}
}