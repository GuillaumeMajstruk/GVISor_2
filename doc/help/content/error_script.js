$(function()
{
	var fatal_part = document.getElementById('fatal_part');
	fatal_part.style.backgroundColor = "#FFC1A1";
	fatal_part.onmouseover = function()
	{
		fatal_part.style.backgroundColor = "#FF9A94";
	};
	fatal_part.onmouseout = function()
	{
		fatal_part.style.backgroundColor = "#FFC1A1";
	};
});