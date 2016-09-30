$(document).ready(function() {
	$(".nav a").on("click", function(){
		$(".nav").find(".active").removeClass("active");
		$(this).parent().addClass("active");
	});

});

$(window).load(function() {
	// Animate loader off screen
	$(".loader").fadeOut("slow");
});