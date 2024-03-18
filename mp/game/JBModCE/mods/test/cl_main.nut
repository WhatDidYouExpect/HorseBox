t <- 0;

function DrawEpicPanel(panel)
{
	SurfaceDrawLine(abs(t%100-50),abs(t%84-42),abs((t-10)%100-50),abs((t-10)%84-42));
	SurfaceDrawLine(abs((t-10)%100-50),abs((t-10)%84-42),abs((t-20)%100-50),abs((t-20)%84-42));
	t += 1;
}

function LevelInitPreEntity()
{
	local th = VGUICreatePanel();
	VGUISetBounds(th,16,16,50,42);
	VGUISetPaintFunction(th,"DrawEpicPanel");
}