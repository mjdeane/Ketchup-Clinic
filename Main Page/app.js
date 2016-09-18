$(document).ready(function() {

	$('#login-enter').click(function() {

		var username = $("[aria-describedby='username-addon']").val();
		if(username == 'dr.mario'){
			window.location.href = '../hospital-page/index.html';
		}
		else{
			window.location.href = '../Village People/index.html';
		}
		
	});

});