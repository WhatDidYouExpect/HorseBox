function OnModStart()
	return "YIPPEEEE"
end


function OnGameFrame()
	if GetConvar("sv_cheats") == "1" then
		SetVelocity(FindEntityByClassname("player",0),0.0,0.0,1000.0)
	end
end