<?php

/**
 * Implements hook_default_rules_configuration().
 */
function commercebox_core_default_rules_configuration() {
  $rules['commerce_checkout_new_account'] = entity_import('rules_config', '{ "commerce_checkout_new_account" : {
    "LABEL" : "Create a new account for an anonymous order",
    "PLUGIN" : "reaction rule",
    "WEIGHT" : "2",
    "TAGS" : [ "Commerce Checkout" ],
    "REQUIRES" : [ "rules", "commerce", "commerce_checkout", "commercebox_core" ],
    "ON" : [ "commerce_checkout_complete" ],
    "IF" : [
      { "data_is" : { "data" : [ "commerce-order:uid" ], "value" : "0" } },
      { "NOT entity_exists" : {
          "type" : "user",
          "property" : "mail",
          "value" : [ "commerce-order:mail" ]
        }
      },
      { "data_is" : { "data" : [ "commerce-order:type" ], "value" : "commerce_order" } }
    ],
    "DO" : [
      { "entity_create" : {
          "USING" : {
            "type" : "user",
            "param_name" : [ "commerce-order:mail-username" ],
            "param_mail" : [ "commerce-order:mail" ]
          },
          "PROVIDE" : { "entity_created" : { "account_created" : "Created account" } }
        }
      },
      { "data_set" : { "data" : [ "account-created:status" ], "value" : 1 } },
      { "entity_save" : { "data" : [ "account-created" ], "immediate" : 1 } },
      { "entity_query" : {
          "USING" : {
            "type" : "user",
            "property" : "mail",
            "value" : [ "commerce-order:mail" ],
            "limit" : 1
          },
          "PROVIDE" : { "entity_fetched" : { "account_fetched" : "Fetched account" } }
        }
      },
      { "LOOP" : {
          "USING" : { "list" : [ "account-fetched" ] },
          "ITEM" : { "list_item" : "Current list item" },
          "DO" : [
            { "send_account_email" : { "account" : [ "list-item" ], "email_type" : "register_admin_created" } },
            { "data_set" : { "data" : [ "commerce-order:uid" ], "value" : [ "list-item:uid" ] } },
            { "data_set" : {
                "data" : [ "commerce-order:commerce-customer-billing:uid" ],
                "value" : [ "list-item:uid" ]
              }
            }
          ]
        }
      },
      { "commercebox_core_log_user_in" : { "account" : [ "account-created" ] } }
    ]
  }
}');

  return $rules;
}

