<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" <?php language_attributes(); ?>>

<head profile="http://gmpg.org/xfn/11">
	
	<meta http-equiv="Content-Type" content="<?php bloginfo('html_type'); ?>; charset=<?php bloginfo('charset'); ?>" />
	
	<?php if (is_search()) { ?>
	   <meta name="robots" content="noindex, nofollow" /> 
	<?php } ?>

	<title>
		   <?php
		      if (function_exists('is_tag') && is_tag()) {
		         single_tag_title("Tag Archive for &quot;"); echo '&quot; - '; }
		      elseif (is_archive()) {
		         wp_title(''); echo ' Archive - '; }
		      elseif (is_search()) {
		         echo 'Search for &quot;'.wp_specialchars($s).'&quot; - '; }
		      elseif (!(is_404()) && (is_single()) || (is_page())) {
		         wp_title(''); echo ' - '; }
		      elseif (is_404()) {
		         echo 'Not Found - '; }
		      if (is_home()) {
		         bloginfo('name'); echo ' - '; bloginfo('description'); }
		      else {
		          bloginfo('name'); }
		      if ($paged>1) {
		         echo ' - page '. $paged; }
		   ?>
	</title>
	
	<link rel="shortcut icon" href="/favicon.ico" type="image/x-icon" />
	
	<link rel="stylesheet" href="<?php bloginfo('stylesheet_url'); ?>" type="text/css" />
	
	<link rel="pingback" href="<?php bloginfo('pingback_url'); ?>" />

	<?php if ( is_singular() ) wp_enqueue_script( 'comment-reply' ); ?>

    <?php wp_enqueue_script("jquery"); ?>
	<?php wp_head(); ?>
	
</head>

<body <?php body_class(); ?> style="margin-top: 114px">
	
    <div id="page-wrap">
        <div id="slider_home_01">

            <div id="slider_home_02">

                <div id="slider_home_03" style="width:565px; height:28px;">
                    <div style="float:left">
                        Call: <?php echo get_option("socialmediax_phone");?>  | Connect : 
                    </div>

                    <div style="position: relative; left: 3px;">
                        <img src= "<?php bloginfo('template_directory'); ?>/images/top_social_icons.png"
                             alt="Follow us on" 
                             border="0" 
                             usemap="#FollowMap" 
                             style="height: 22px;" 
                        />	
                    </div>
                </div>

                <map name="FollowMap" id="FollowMap">
                    <area shape="circle" coords="12,11,10" target="_blank" alt="" 
                          href="http://twitter.com/<?php echo get_option("socialmediax_twitter"); ?>"  />

                    <area shape="circle" coords="35,11,10" target="_blank" alt="Connect with us on LinkedIN"
                          href="<?php echo get_option('socialmediax_linkedin'); ?>"  />

                    <area shape="circle" coords="58,11,10" alt="Mail To Esocial Media" 
                          href="mailto:<?php echo get_option('socialmediax_email'); ?>"  />

                    <area shape="circle" coords="82,10,10" target="_blank" alt="View our Videos" 
                          href="<?php echo get_option('socialmediax_youtube'); ?>"  />

                    <area shape="circle" coords="105,11,10"  target="_blank" alt="Subscribe to our Feeds" 
                          href="http://feeds.feedburner.com/eSocialMedia" />
                </map>	

                <div id="header">
                    <div style="float:left; margin-right:10px;">	
                        <a href="<?php echo home_url( '/' ); ?>">
                            <img src="<?php bloginfo('template_directory'); ?>/images/logo.jpg"
                                 alt="<?php bloginfo( 'name' ); ?>" id="logo"/>
                        </a>
                    </div>

                    <div style="float:left; width: 710px; margin-top:15px;">
                        <?php wp_nav_menu( array( 'theme_location' => 'primary', 'menu_class' => 'nav-menu' ) ); ?>
                    </div>

                </div>
            </div>
        <div class="shadow"></div>
        </div>



