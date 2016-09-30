$(document).ready(function() {
	$(".nav a").on("click", function(){
		$(".nav").find(".active").removeClass("active");
		$(this).parent().addClass("active");
	s
	});
	var scroll_start = 0;
	var startchange = $('.nav');
	var offset = startchange.offset();
	$(document).scroll(function() {
		scroll_start = $(this).scrollTop();
		if(scroll_start > offset.top) {
			$('.navbar-fixed-top').css('opacity', '0.8');
		} else {
			$('.navbar-fixed-top').css('opacity', '1');
		}
	});

});

