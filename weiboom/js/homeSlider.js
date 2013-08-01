// fix pre overflow in IE

jQuery(document).ready(function($) {
	//$("#featured-promotions").accordion({ autoHeight: false,collapsible: true, active:false });
	$("#featured-promotions").easySlider();
	$("#rotator_home")
        .cycle({ 
	    fx: 'fade',
	    timeout: 15000,
	    speed: 2500,
        pager:'#dots'
	});
});
