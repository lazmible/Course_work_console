#pragma once

#include <map>
#include <string>

#pragma region attribute_values
// В куче атрибутов есть значения по умолчанию, надо видимо как-то учитывать их в классе


#define ATTR_ACCESS_KEY_VALS       ("[0-9a-z]"               )  // numbers from 0 to 9 + little latinian letters
#define ATTR_CLASS_VALS            ("[0-9a-zA-Z-_]+"         )  // numbers from 0 to 9 + latinian letters + "-" and "_"
#define ATTR_CONTENTEDITABLE_VALS  ("(true|false|)"          )  // "true" , "false" or empty string
#define ATTR_CONTEXTMENU_VALS      ("[a-zA-Z]+"              )  // !!!!! тут более сложная логика, чекни сайт
#define ATTR_DIR_VALS              ("(ltr|rtl)"              )  // "ltr" or "rtl"
#define ATTR_HIDDEN_VALS           ("(hidden|)"              )  // может вообще быть без строки, надо чекать выше по логике
#define ATTR_ID_VALS               ("[a-zA-Z][a-zA-Z0-9-_]*" )
#define ATTR_LANG_VALS             ("kek")                         // ебучий шаблон с кучей ебучих кодов языков, смотри на сайте, там много писать((((9
#define ATTR_SPELLCHECK_VALS       ("(true|false|)"          )  // "true" , "false" or empty string
#define ATTR_STYLE_VALS            ("[a-zA-Z0-9;:]+"         )  // CSS syntax
#define ATTR_TABINDEX_VALS         ("[0-9]+"                 )  // positive integer value
#define ATTR_TITLE_VALS            (".+"                     )  // any text
#define ATTR_XMLLANG_VALS "kek"
#define ATTR_ONBLUR_VARS     "kek"
#define ATTR_ONCHANGE_VARS "kek"
#define ATTR_ONCLICK_VALS "kek"
#define ATTR_ONBLCLICK_VALS "kek"
#define ATTR_ONFOCUS_VALS "kek"
#define ATTR_ONKEYDOWN_VALS "kek"
#define ATTR_ONKEYPRESS_VALS "kek"
#define ATTR_ONKEYUP_VALS "kek"
#define ATTR_ONLOAD_VALS "kek"
#define ATTR_ONMOUSEDOWN_VALS "kek"
#define ATTR_ONMOUSEMOVE_VALS "kek"
#define ATTR_ONMOUSEOUT_VALS "kek"
#define ATTR_ONMOUSEOVER_VALS "kek"
#define ATTR_ONMOUSEUP_VALS "kek"
#define ATTR_ONRESET_VALS "kek"
#define ATTR_ONSELECT_VALS "kek"
#define ATTR_ONSUBMIT_VALS "kek"
#define ATTR_ONUNLOAD_VALS "kek"
#define ATTR_ACCEPT_VALS "kek"
#define ATTR_ACCEPTCHARSET_VALS "kek"
#define ATTR_ACTION_VALS "kek"
#define ATTR_ALIGN_VALS "kek"
#define ATTR_ALINK_VALS "kek"
#define ATTR_ALLOWTRANSPARENCY_VALS "kek"
#define ATTR_ALT_VALS "kek"
#define ATTR_ARCHIVE_VALS "kek"
#define ATTR_ASYNC_VALS "kek"
#define ATTR_AUTOCOMPLETE_VALS "kek"
#define ATTR_AUTOFOCUS_VALS "kek" 
#define ATTR_AUTOPLAY_VALS "kek"
#define ATTR_AXIS_VALS "kek"
#define ATTR_BACKGROUND_VALS "kek"
#define ATTR_BALANCE_VALS "kek"
#define ATTR_BEHAVIOR_VALS "kek"
#define ATTR_BGCOLOR_VALS "kek"
#define ATTR_BGPROPERTIES_VALS "kek"
#define ATTR_BORDER_VALS "kek"
#define ATTR_BORDERCOLOR_VALS "kek"
#define ATTR_BOOTONMARGIN_VALS "kek"
#define ATTR_CHALLENGE_VALS "kek"
#define ATTR_CHAR_VALS "kek" 
#define ATTR_CHAROFF_VALS "kek"
#define ATTR_CHARSET_VALS "kek"
#define ATTR_CHECKED_VALS "kek"
#define ATTR_CELLPADDING_VALS "kek"
#define ATTR_CELLSPACING_VALS "kek"
#define ATTR_CITE_VALS "kek"
#define ATTR_CLASSID_VALS "kek"
#define ATTR_CLEAR_VALS "kek"
#define ATTR_CODE_VALS "kek"
#define ATTR_CODEBASE_VALS "kek"
#define ATTR_CODETYPE_VALS "kek"
#define ATTR_CONTENT_VALS "kek"
#define ATTR_CONTROLS_VALS "kek"
#define ATTR_COLOR_VALS "kek"
#define ATTR_COLS_VALS "kek"
#define ATTR_CLOSPAN_VALS "kek"
#define ATTR_COORDS_VALS "kek"
#define ATTR_DATA_VALS "kek"
#define ATTR_DATETIME_VALS "kek"
#define ATTR_DEFAULT_VALS "kek"
#define ATTR_DEFER_VALS "kek"
#define ATTR_DIRECTION_VALS "kek"
#define ATTR_DISABLED_VALS "kek"
#define ATTR_DOWNLOAD_VALS "kek"
#define ATTR_ENCTYPE_VALS "kek"
#define ATTR_FACE_VALS "kek"
#define ATTR_FRAME_VALS "kek"
#define ATTR_FRAMEBORDER_VALS "kek"
#define ATTR_FRAMESPACING_VALS "kek"
#define ATTR_FOR_VALS "kek"
#define ATTR_FORM_VALS "kek"
#define ATTR_FORMACTION_VALS "kek"
#define ATTR_FORMENCTYPE_VALS "kek"
#define ATTR_FORMMETHOD_VALS "kek"
#define ATTR_FORMOVALIDATE_VALS "kek"
#define ATTR_FORMTARGET_VALS "kek"
#define ATTR_GUTTER_VALS "kek"
#define ATTR_HEADERS_VALS "kek"
#define ATTR_HEIGHT_VALS "kek"
#define ATTR_HREF_VALS "kek"
#define ATTR_HREFLANG_VALS "kek"
#define ATTR_HSPACE_VALS "kek"
#define ATTR_HTTPEQUIV_VALS "kek"
#define ATTR_ICON_VALS "kek"
#define ATTR_ISMAP_VALS "kek"
#define ATTR_KEYTYPE_VALS "kek"
#define ATTR_KIND_VALS "kek"
#define ATTR_LABEL_VALS "kek"
#define ATTR_LANGUAGE_VALS "kek"
#define ATTR_LEFTMARGIN_VALS "kek"
#define ATTR_LINK_VALS "kek"
#define ATTR_LIST_VALS "kek"
#define ATTR_LONGDESC_VALS "kek"
#define ATTR_LOOP_VALS "kek"
#define ATTR_LOW_VALS "kek"
#define ATTR_LOWSRC_VALS "kek"
#define ATTR_MANIFEST_VALS "kek"
#define ATTR_MARGINHEIGHT_VALS "kek"
#define ATTR_MARGINWIDTH_VALS "kek"
#define ATTR_MAX_VALS "kek"
#define ATTR_MAXLEGHT_VALS "kek"
#define ATTR_MEDIA_VALS "kek"
#define ATTR_METHOD_VALS "kek"
#define ATTR_MIN_VALS "kek"
#define ATTR_MULTIPLE_VALS "kek"
#define ATTR_MUTED_VALS "kek"
#define ATTR_NAME_VALS "kek"
#define ATTR_NOHREF_VALS "kek"
#define ATTR_NORESIZE_VALS "kek"
#define ATTR_NOSHADE_VALS "kek"
#define ATTR_NOVALIDATE_VALS "kek"
#define ATTR_NOWRAP_VALS "kek"
#define ATTR_OPEN_VALS "kek"
#define ATTR_OPTIMUM_VALS "kek"
#define ATTR_PATTERN_VALS "kek"
#define ATTR_PLACEHOLDER_VALS "kek"
#define ATTR_PLUGINSPAGE_VALS "kek"
#define ATTR_POSTER_VALS "kek"
#define ATTR_PRELOAD_VALS "kek"
#define ATTR_PROMPT_VALS "kek"
#define ATTR_PUBDATE_VALS "kek"
#define ATTR_RADIOGROUP_VALS "kek"
#define ATTR_READONLY_VALS "kek"
#define ATTR_REL_VALS "kek"
#define ATTR_REQUIRED_VALS "kek"
#define ATTR_RESERVED_VALS "kek"
#define ATTR_RIGHTMARGIN_VALS "kek"
#define ATTR_ROWS_VALS "kek"
#define ATTR_ROWSPAN_VALS "kek"
#define ATTR_RULES_VALS "kek"
#define ATTR_SANDBOX_VALS "kek"
#define ATTR_SCOPE_VALS "kek"
#define ATTR_SCROLL_VALS "kek"
#define ATTR_SCROLLAMOUNT_VALS "kek"
#define ATTR_SCROLLDELAY_VALS  "kek"
#define ATTR_SCROLLING_VALS "kek"
#define ATTR_SHAPE_VALS "kek"
#define ATTR_SEAMLESS_VALS "kek"
#define ATTR_SELECTED_VALS "kek"
#define ATTR_SIZE_VALS "kek"
#define ATTR_SIZES_VALS "kek"
#define ATTR_SPAN_VALS  "kek"
#define ATTR_SRC_VALS "kek"
#define ATTR_SRCLANG_VALS  "kek"
#define ATTR_SRCDOC_VALS "kek"
#define ATTR_START_VALS "kek"
#define ATTR_STEP_VALS "kek"
#define ATTR_SUMMARY_VALS "kek"
#define ATTR_TARGET_VALS "kek"
#define ATTR_TEXT_VALS "kek"
#define ATTR_TOPMARGIN_VALS "kek"
#define ATTR_TRUESPEED_VALS "kek" 
#define ATTR_TYPE_VALS "kek"
#define ATTR_USEMAP_VALS "kek"
#define ATTR_VALIGN_VALS "kek"
#define ATTR_VALUE_VALS "kek"
#define ATTR_VALUETYPE_VALS "kek"
#define ATTR_VLINK_VALS "kek"
#define ATTR_VOLUME_VALS "kek"
#define ATTR_VSPACE_VALS "kek"
#define ATTR_WIDTH_VALS "kek"
#define ATTR_WRAP_VALS "kek"
#define ATTR_XMLNS_VALS "kek"
#define ATTR_ABBR_VALS "kek"
#pragma endregion

#pragma region database_definition

#define ATTR_DATABASE_HTML5                                      \
{                                                                \
	{  "accesskey"          , ATTR_ACCESS_KEY_VALS           },  \
	{  "class"              , ATTR_CLASS_VALS                },  \
	{  "contenteditable"    , ATTR_CONTENTEDITABLE_VALS      },  \
	{  "contextmenu"        , ATTR_CONTEXTMENU_VALS          },  \
	{  "dir"                , ATTR_DIR_VALS                  },  \
	{  "hidden"             , ATTR_HIDDEN_VALS               },  \
	{  "id"                 , ATTR_ID_VALS                   },  \
	{  "lang"               , ATTR_LANG_VALS                 },  \
	{  "spellcheck"         , ATTR_SPELLCHECK_VALS           },  \
	{  "style"              , ATTR_STYLE_VALS                },  \
	{  "tabindex"           , ATTR_TABINDEX_VALS             },  \
	{  "title"              , ATTR_TITLE_VALS                },  \
	{  "xml:lang"           , ATTR_XMLLANG_VALS              },  \
	{  "onblur"             , ATTR_ONBLUR_VARS               },  \
	{  "onchange"           , ATTR_ONCHANGE_VARS             },  \
	{  "onclick"            , ATTR_ONCLICK_VALS              },  \
	{  "ondblclick"         , ATTR_ONBLCLICK_VALS            },  \
	{  "onfocus"            , ATTR_ONFOCUS_VALS              },  \
	{  "onkeydown"          , ATTR_ONKEYDOWN_VALS            },  \
	{  "onkeypress"         , ATTR_ONKEYPRESS_VALS           },  \
	{  "onkeyup"            , ATTR_ONKEYUP_VALS              },  \
	{  "onload"             , ATTR_ONLOAD_VALS               },  \
	{  "onmousedown"        , ATTR_ONMOUSEDOWN_VALS          },  \
	{  "onmousemove"        , ATTR_ONMOUSEMOVE_VALS          },  \
	{  "onmouseout"         , ATTR_ONMOUSEOUT_VALS           },  \
	{  "onmouseover"        , ATTR_ONMOUSEOVER_VALS          },  \
	{  "onmouseup"          , ATTR_ONMOUSEUP_VALS            },  \
	{  "onreset"            , ATTR_ONRESET_VALS              },  \
	{  "onselect"           , ATTR_ONSELECT_VALS             },  \
	{  "onsubmit"           , ATTR_ONSUBMIT_VALS             },  \
	{  "onunload"           , ATTR_ONUNLOAD_VALS             },  \
	{  "abbr"               , ATTR_ABBR_VALS                 },  \
	{  "accept"             , ATTR_ACCEPT_VALS               },  \
	{  "accept-charset"     , ATTR_ACCEPTCHARSET_VALS        },  \
	{  "action"             , ATTR_ACTION_VALS               },  \
	{  "align"              , ATTR_ALIGN_VALS                },  \
	{  "alink"              , ATTR_ALINK_VALS                },  \
	{  "allowtransparency"  , ATTR_ALLOWTRANSPARENCY_VALS    },  \
	{  "alt"                , ATTR_ALT_VALS                  },  \
	{  "archive"            , ATTR_ARCHIVE_VALS              },  \
	{  "async"              , ATTR_ASYNC_VALS                },  \
	{  "autocomplete"       , ATTR_AUTOCOMPLETE_VALS         },  \
	{  "autofocus"          , ATTR_AUTOFOCUS_VALS            },  \
	{  "autoplay"           , ATTR_AUTOPLAY_VALS             },  \
	{  "axis"               , ATTR_AXIS_VALS                 },  \
	{  "background"         , ATTR_BACKGROUND_VALS           },  \
	{  "balance"            , ATTR_BALANCE_VALS              },  \
	{  "behavior"           , ATTR_BEHAVIOR_VALS             },  \
	{  "bgcolor"            , ATTR_BGCOLOR_VALS              },  \
	{  "bgproperties"       , ATTR_BGPROPERTIES_VALS         },  \
	{  "border"             , ATTR_BORDER_VALS               },  \
	{  "bordercolor"        , ATTR_BORDERCOLOR_VALS          },  \
	{  "bottommargin"       , ATTR_BOOTONMARGIN_VALS         },  \
	{  "challenge"          , ATTR_CHALLENGE_VALS            },  \
	{  "char"               , ATTR_CHAR_VALS                 },  \
	{  "charoff"            , ATTR_CHAROFF_VALS              },  \
	{  "charset"            , ATTR_CHARSET_VALS              },  \
	{  "checked"            , ATTR_CHECKED_VALS              },  \
	{  "cellpadding"        , ATTR_CELLPADDING_VALS          },  \
	{  "cellspacing"        , ATTR_CELLSPACING_VALS          },  \
	{  "cite"               , ATTR_CITE_VALS                 },  \
	{  "classid"            , ATTR_CLASSID_VALS              },  \
	{  "clear"              , ATTR_CLEAR_VALS                },  \
	{  "code"               , ATTR_CODE_VALS                 },  \
	{  "codebase"           , ATTR_CODEBASE_VALS             },  \
	{  "codetype"           , ATTR_CODETYPE_VALS             },  \
	{  "content"            , ATTR_CONTENT_VALS              },  \
	{  "controls"           , ATTR_CONTROLS_VALS             },  \
	{  "color"              , ATTR_COLOR_VALS                },  \
	{  "cols"               , ATTR_COLS_VALS                 },  \
	{  "colspan"            , ATTR_CLOSPAN_VALS              },  \
	{  "coords"             , ATTR_COORDS_VALS               },  \
	{  "data"               , ATTR_DATA_VALS                 },  \
	{  "datetime"           , ATTR_DATETIME_VALS             },  \
	{  "default"            , ATTR_DEFAULT_VALS              },  \
	{  "defer"              , ATTR_DEFER_VALS                },  \
	{  "direction"          , ATTR_DIRECTION_VALS            },  \
	{  "disabled"           , ATTR_DISABLED_VALS             },  \
	{  "download"           , ATTR_DOWNLOAD_VALS             },  \
	{  "enctype"            , ATTR_ENCTYPE_VALS              },  \
	{  "face"               , ATTR_FACE_VALS                 },  \
	{  "frame"              , ATTR_FRAME_VALS                },  \
	{  "frameborder"        , ATTR_FRAMEBORDER_VALS          },  \
	{  "framespacing"       , ATTR_FRAMESPACING_VALS         },  \
	{  "for"                , ATTR_FOR_VALS                  },  \
	{  "form"               , ATTR_FORM_VALS                 },  \
	{  "formaction"         , ATTR_FORMACTION_VALS           },  \
	{  "formenctype"        , ATTR_FORMENCTYPE_VALS          },  \
	{  "formmethod"         , ATTR_FORMMETHOD_VALS           },  \
	{  "formnovalidate"     , ATTR_FORMOVALIDATE_VALS        },  \
	{  "formtarget"         , ATTR_FORMTARGET_VALS           },  \
	{  "gutter"             , ATTR_GUTTER_VALS               },  \
	{  "headers"            , ATTR_HEADERS_VALS              },  \
	{  "height"             , ATTR_HEIGHT_VALS               },  \
	{  "href"               , ATTR_HREF_VALS                 },  \
	{  "hreflang"           , ATTR_HREFLANG_VALS             },  \
	{  "hspace"             , ATTR_HSPACE_VALS               },  \
	{  "http-equiv"         , ATTR_HTTPEQUIV_VALS            },  \
	{  "icon"               , ATTR_ICON_VALS                 },  \
	{  "ismap"              , ATTR_ISMAP_VALS                },  \
	{  "keytype"            , ATTR_KEYTYPE_VALS              },  \
	{  "kind"               , ATTR_KIND_VALS                 },  \
	{  "label"              , ATTR_LABEL_VALS                },  \
	{  "language"           , ATTR_LANGUAGE_VALS             },  \
	{  "leftmargin"         , ATTR_LEFTMARGIN_VALS           },  \
	{  "link"               , ATTR_LINK_VALS                 },  \
	{  "list"               , ATTR_LIST_VALS                 },  \
	{  "longdesc"           , ATTR_LONGDESC_VALS             },  \
	{  "loop"               , ATTR_LOOP_VALS                 },  \
	{  "low"                , ATTR_LOW_VALS                  },  \
	{  "lowsrc"             , ATTR_LOWSRC_VALS               },  \
	{  "manifest"           , ATTR_MANIFEST_VALS             },  \
	{  "marginheight"       , ATTR_MARGINHEIGHT_VALS         },  \
	{  "marginwidth"        , ATTR_MARGINWIDTH_VALS          },  \
	{  "max"                , ATTR_MAX_VALS                  },  \
	{  "maxlength"          , ATTR_MAXLEGHT_VALS             },  \
	{  "media"              , ATTR_MEDIA_VALS                },  \
	{  "method"             , ATTR_METHOD_VALS               },  \
	{  "min"                , ATTR_MIN_VALS                  },  \
	{  "multiple"           , ATTR_MULTIPLE_VALS             },  \
	{  "muted"              , ATTR_MUTED_VALS                },  \
	{  "name"               , ATTR_NAME_VALS                 },  \
	{  "nohref"             , ATTR_NOHREF_VALS               },  \
	{  "noresize"           , ATTR_NORESIZE_VALS             },  \
	{  "noshade"            , ATTR_NOSHADE_VALS              },  \
	{  "novalidate"         , ATTR_NOVALIDATE_VALS           },  \
	{  "nowrap"             , ATTR_NOWRAP_VALS               },  \
	{  "open"               , ATTR_OPEN_VALS                 },  \
	{  "optimum"            , ATTR_OPTIMUM_VALS              },  \
	{  "pattern"            , ATTR_PATTERN_VALS              },  \
	{  "placeholder"        , ATTR_PLACEHOLDER_VALS          },  \
	{  "pluginspage"        , ATTR_PLUGINSPAGE_VALS          },  \
	{  "poster"             , ATTR_POSTER_VALS               },  \
	{  "preload"            , ATTR_PRELOAD_VALS              },  \
	{  "prompt"             , ATTR_PROMPT_VALS               },  \
	{  "pubdate"            , ATTR_PUBDATE_VALS              },  \
	{  "radiogroup"         , ATTR_RADIOGROUP_VALS           },  \
	{  "readonly"           , ATTR_READONLY_VALS             },  \
	{  "rel"                , ATTR_REL_VALS                  },  \
	{  "required"           , ATTR_REQUIRED_VALS             },  \
	{  "reserved"           , ATTR_RESERVED_VALS             },  \
	{  "rightmargin"        , ATTR_RIGHTMARGIN_VALS          },  \
	{  "rows"               , ATTR_ROWS_VALS                 },  \
	{  "rowspan"            , ATTR_ROWSPAN_VALS              },  \
	{  "rules"              , ATTR_RULES_VALS                },  \
	{  "sandbox"            , ATTR_SANDBOX_VALS              },  \
	{  "scope"              , ATTR_SCOPE_VALS                },  \
	{  "scroll"             , ATTR_SCROLL_VALS               },  \
	{  "scrollamount"       , ATTR_SCROLLAMOUNT_VALS         },  \
	{  "scrolldelay"        , ATTR_SCROLLDELAY_VALS          },  \
	{  "scrolling"          , ATTR_SCROLLING_VALS            },  \
	{  "shape"              , ATTR_SHAPE_VALS                },  \
	{  "seamless"           , ATTR_SEAMLESS_VALS             },  \
	{  "selected"           , ATTR_SELECTED_VALS             },  \
	{  "size"               , ATTR_SIZE_VALS                 },  \
	{  "sizes"              , ATTR_SIZES_VALS                },  \
	{  "span"               , ATTR_SPAN_VALS                 },  \
	{  "src"                , ATTR_SRC_VALS                  },  \
	{  "srclang"            , ATTR_SRCLANG_VALS              },  \
	{  "srcdoc"             , ATTR_SRCDOC_VALS               },  \
	{  "start"              , ATTR_START_VALS                },  \
	{  "step"               , ATTR_STEP_VALS                 },  \
	{  "summary"            , ATTR_SUMMARY_VALS              },  \
	{  "target"             , ATTR_TARGET_VALS               },  \
	{  "text"               , ATTR_TEXT_VALS                 },  \
	{  "topmargin"          , ATTR_TOPMARGIN_VALS            },  \
	{  "truespeed"          , ATTR_TRUESPEED_VALS            },  \
	{  "type"               , ATTR_TYPE_VALS                 },  \
	{  "usemap"             , ATTR_USEMAP_VALS               },  \
	{  "valign"             , ATTR_VALIGN_VALS               },  \
	{  "value"              , ATTR_VALUE_VALS                },  \
	{  "valuetype"          , ATTR_VALUETYPE_VALS            },  \
	{  "vlink"              , ATTR_VLINK_VALS                },  \
	{  "volume"             , ATTR_VOLUME_VALS               },  \
	{  "vspace"             , ATTR_VSPACE_VALS               },  \
	{  "width"              , ATTR_WIDTH_VALS                },  \
	{  "wrap"               , ATTR_WRAP_VALS                 },  \
	{  "xmlns"              , ATTR_XMLNS_VALS                }   \
}

#pragma endregion

//std::map<std::string, std::string> AttributeDatabase = ATTR_DATABASE_HTML5;