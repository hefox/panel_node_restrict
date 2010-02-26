Panels node restrict (panels_node_restrict)

Panels node restrict serves to ease use of panels node when non-technical
administrator users are an issue.

It achieves this end via 2 ways

1) It restricts access to panels node's panel content/layout and layout selection to 
"administer panel node content" permission, with the purpose of making making panel 
node content/layout a super-role like task.
2) If set to under it's setting page (admin/build/panels/settings/panel-node-restrict),
It shares panel content/layout among nodes connected via a translation id (using the
source translation's panel content).

-------

This module is intended for when a technical user needs to allow non-technical users
to edit node content of panels nodes.

Out of the box panels_node, cck fields and other node content (excluding body 
field), can be added to panel content, but also they can displayed as normal 
with panel content appended to the end. So some parts of the panel node, for 
example a cck text field, are desirable for a non-technical user to edit but not
the actual panel-content and panel-layout. 

Hooks Implemented
-----------------

panels_node_restrict_perm 
  Defines the "administer panel node content" permission
  
panels_node_restrict_menu_alter
  Changes the access on "node/%node/panel_layout", "node/%node/panel_content",
  "node/add/panel/choose-layout" to permission check.

panels_node_restrict_nodeapi
  Sets the creation layout under certian conditions and changes the display 
  information for translated nodes.
  
panels_node_restrict_form_panels_edit_display_form_alter
  Adds a message when editing panel content of a translated node that the
  content that is being edited is the source translations content.
  


Additional Behaviors
--------------------

Default layout:
  Provides an option to use a default layout despite permission to edit 
  panel layout, so the layout selection screen can be skipped. 