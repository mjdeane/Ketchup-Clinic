$(document).ready(function() {

	$('.instance-list').css("display", "inline");

	var names = localStorage.getItem("names");
	var namesArr = null;

	if(names != null){
		namesArr = names.split(";");
	}

	if(namesArr != null){
		for(var i = 0; i < namesArr.length; i++){
			var element = "<option href=\"#\">" + namesArr[i] + "</option>";
			$('#patient-dropdown').append(element);
		}
	}

	$('.instance-list td').click(function() {
		$('.session-info').css("display", "inline");
	});
});