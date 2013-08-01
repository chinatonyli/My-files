<?php
	
	// Add RSS links to <head> section
    add_theme_support('automatic-feed-links');
	
	// Load jQuery
	// if ( !is_admin() ) {
	//    wp_deregister_script('jquery');
	//    wp_register_script('jquery', ("http://ajax.googleapis.com/ajax/libs/jquery/1.4.1/jquery.min.js"), false);
	//    wp_enqueue_script('jquery');
	// }
	
	// Clean up the <head>
	function removeHeadLinks() {
    	remove_action('wp_head', 'rsd_link');
    	remove_action('wp_head', 'wlwmanifest_link');
    }
    add_action('init', 'removeHeadLinks');
    remove_action('wp_head', 'wp_generator');
    
    if (function_exists('register_sidebar')) {
    	register_sidebar(array(
    		'name' => 'Sidebar Widgets',
    		'id'   => 'sidebar-widgets',
    		'description'   => 'These are widgets for the sidebar.',
    		'before_widget' => '<div id="%1$s" class="widget %2$s">',
    		'after_widget'  => '</div>',
    		'before_title'  => '<h2>',
    		'after_title'   => '</h2>'
    	));
    }

/**
 * Makes our wp_nav_menu() fallback -- wp_page_menu() -- show a home link.
 *
 * @since Twenty Twelve 1.0
 */
function socialmediax_page_menu_args( $args ) {
	if ( ! isset( $args['show_home'] ) )
		$args['show_home'] = true;
	return $args;
}
add_filter( 'wp_page_menu_args', 'socialmediax_page_menu_args' );

/**
 * Makes our wp_nav_menu() fallback -- wp_page_menu() -- Use custom id and class.
 *
 * @since Twenty Twelve 1.0
 */
function socialmediax_page_menu($output) {
    $output = str_replace("<ul>", "<ul id=\"primary\" class=\"dropdown\">", $output);
    return $output;
}
add_filter( 'wp_page_menu', 'socialmediax_page_menu');

function socialmediax_setup_theme_admin_menus() {
    add_submenu_page("themes.php", "Main Settings Elements", "Social Media X",
                     "manage_options", "main-settings-elements", "main_settings");
}
add_action("admin_menu", "socialmediax_setup_theme_admin_menus");

function main_settings_menu_item($name, $text, $variable, $size=25) {
?>
    <tr valign="top">
        <th scope="row">
            <label for="<?php echo $name; ?>">
                <?php echo $text; ?>
            </label>
        </th>
        <td>
            <input type="text" name="<?php echo $name ?>" size="<?php echo $size; ?>"
                   value="<?php echo $variable; ?>" />
        <td>
<?php
}


function main_settings() {
    if (!current_user_can('manage_options')) {  
        wp_die('You do not have sufficient permissions to access this page.');  
    }  
    $phone = get_option("socialmediax_phone");
    $twitter = get_option("socialmediax_twitter");
    $facebook = get_option("socialmediax_facebook");
    $linkedin = get_option("socialmediax_linkedin");
    $email = get_option("socialmediax_email");
    $youtube = get_option("socialmediax_youtube");
    $about_us = get_option('socialmediax_about_us');
    $slider1_link = get_option('socialmediax_slider1_link');
    ?>
       <div class="wrap">  
        <?php screen_icon('themes'); ?> <h2>Social Media X Settings</h2>  
  
        <form method="POST" action="">  
            <table class="form-table">  
                <?php main_settings_menu_item("phone_num_elements", "Phone Number: ", $phone); 
                      main_settings_menu_item("twitter", "Twitter: ", $twitter);
                      main_settings_menu_item("facebook", "Facebook: ", $facebook);
                      main_settings_menu_item("linkedin", "LinkedIn: ", $linkedin);
                      main_settings_menu_item("email", "Email: ", $email);
                      main_settings_menu_item("youtube", "YouTube: ", $youtube);
                      main_settings_menu_item("about_us", "About Us: ", $about_us, 50);
                      main_settings_menu_item("slider1_link", "Text for Slider 1", $slider1_link);
                ?>
            </table>  
            <p>  
                <input type="submit" value="Save settings" class="button-primary"/>  
            </p>  
            <input type="hidden" name="update_settings" value="Y" />  
        </form>  
    </div>  
    <?php
        if (isset($_POST["update_settings"])) {  
            $phone = esc_attr($_POST['phone_num_elements']);
            $facebook = esc_attr($_POST['facebook']);
            $twitter = esc_attr($_POST['twitter']);
            $linkedin = esc_attr($_POST['linkedin']);
            $email = esc_attr($_POST['email']);
            $youtube = esc_attr($_POST['youtube']);
            $about_us = esc_attr($_POST['about_us']);
            $slider1_link = esc_attr($_POST['slider1_link']);
            update_option("socialmediax_phone", $phone);
            update_option("socialmediax_facebook", $facebook);
            update_option("socialmediax_twitter", $twitter);
            update_option("socialmediax_linkedin", $linkedin);
            update_option("socialmediax_email", $email);
            update_option("socialmediax_youtube", $youtube);
            update_option("socialmediax_about_us", $about_us);
            update_option("socialmediax_slider1_link", $slider1_link);
            ?>  
            <div id="message" class="updated">Settings saved</div>  
        <?php  
        }  
}?>
