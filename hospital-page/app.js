$(document).ready(function() {

	$('#instance-list').hide();
	$('#patient-info').hide();

	$('#patient-dropdown').change(function() {
		$('#instance-list').show();
	});

	$('#instance-list td').click(function() {
		$('#patient-info').show();
	});
	
});