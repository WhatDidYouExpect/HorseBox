function OnModStart()
{
	return 4;
}

function OnClientExecCmd(client,cmd)
{
	PrintToServer(client.tostring()+": "+cmd+"\n");
	return 1;
}