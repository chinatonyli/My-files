<html>

<head>

<title>Test</title>
<meta content="">
<link rel="stylesheet" type="text/css" media="screen" href="<?php bloginfo('template_directory'); ?>/style.css">
<link rel="stylesheet" type="text/css" media="screen" href="<?php bloginfo('template_directory'); ?>/style_homepage.css">

<?php wp_enqueue_script("jquery"); ?>
<?php wp_head(); ?>
<script src="<?php echo get_template_directory_uri(); ?>/js/easySlider1.7.js" type="text/javascript"></script>
<script src="<?php echo get_template_directory_uri(); ?>/js/jquery.cycle.all.js" type="text/javascript"></script>



</head>

<body class="home blog cufon-disabled chrome" style="margin-top: 114px;">
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
    <div>
    <div style="background-image:url(http://www.esocialmedia.co.uk/wp-content/themes/EsmIndia/images/shadow2.png);height:30px;background-position: center;background-repeat: no-repeat;">
    </div>



</div>

</body>
</html> 
