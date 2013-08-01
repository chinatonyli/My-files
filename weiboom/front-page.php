<?php get_header(); ?>
<link rel="stylesheet" type="text/css" media="screen" href="<?php bloginfo('template_directory'); ?>/css/homepage.css">
<script src="<?php echo get_template_directory_uri(); ?>/js/easySlider1.7.js" type="text/javascript"></script>
<script src="<?php echo get_template_directory_uri(); ?>/js/jquery.cycle.all.js" type="text/javascript"></script>
<script src="<?php echo get_template_directory_uri(); ?>/js/homeSlider.js" type="text/javascript"></script>


<div id="container">
		<div id="container2"></div>
</div>

    <div id="page">
	<a href="https://plus.google.com/100273726197610972906" rel="publisher" style="display:none;">Find us on Google+</a>

	<div id="fullheader">
		<div id="rotator_home">
            <a href="<?php echo get_option('socialmediax_slider1_link'); ?>"	style="background-image: url('<?php bloginfo('template_directory'); ?>/images/slider/clients.png'); background-color: #fff; position: absolute; top: 0px; left: 0px; display: block; z-index: 6; opacity: 1; width: 10000px; height: 403px; background-position: 50% 0%; background-repeat: no-repeat;"></a>

			<a href="http://esocialmedia.co.uk/what-we-know/" style="background-image: url('<?php bloginfo('template_directory'); ?>/images/slider/Slider-not-many-companies-can-do-this-2.jpg'); background-color: #fff; position: absolute; top: 0px; left: 0px; display: none; z-index: 5; opacity: 0; width: 10000px; height: 403px; background-position: 50% 0%; background-repeat: no-repeat;"></a>

			<a href="http://esocialmedia.co.uk/what-we-do/advice/" style="background-image:url('<?php bloginfo('template_directory'); ?>/images/slider/slider-what-is-social-media-23.jpg'); background-color: #fff; position: absolute; top: 0px; left: 0px; display: none; z-index: 5; opacity: 0; width: 10000px; height: 403px; background-position: 50% 0%; background-repeat: no-repeat;"></a>
		</div>
	</div>
</div>
    <div id="dots"></div>
</div>
<div class="shadow"></div>

<div style="width: 960px; margin: auto;">

<h2 style="width: 304px;">About Us</h2>

<p style="line-height: 22px; margin-right: 17px; text-align: justify; margin-top: 10px;">
    <?php echo get_option('socialmediax_about_us'); ?>
</p>

</div>
<?php get_footer(); ?>
