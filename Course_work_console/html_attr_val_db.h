#pragma once

#include <map>
#include <string>

#pragma region Language code regex definition
#define LANGUAGE_CODE \
"(ab|az|ay|sq|en|en-us|ar|hy|as|af|ba|be|bn|bg|br|cy|hu|vi|gl|\
nl|el|ka|gn|da|zu|iw|ji|in|ia|ga|is|es|it|kk|km|ca|ks|qu|ky|\
zh|ko|co|ku|lo|lv|la|lt|mg|ms|mt|mi|mk|mo|mn|na|de|ne|no|pa|\
fa|pl|ps|rm|ro|ru|sm|sa|sr|sk|sl|so|sw|su|tl|tg|th|ta|tt|bo|\
to|tr|tk|uz|uk|ur|fj|fi|fr|fy|ha|hi|hr|cs|sv|eo|et|jw|ja)"
#pragma endregion

#pragma region Mime type regex definition
#define MIME_TYPE \
"(application/postscript|\
audio/aiff|\
audio/x-aiff|\
application/x-navi-animation|\
application/x-nokia-9000-communicator-add-on-software|\
application/mime|\
application/octet-stream|\
application/arj|\
image/x-jg|\
video/x-ms-asf|\
text/x-asm|\
text/asp|\
application/x-mplayer2|\
video/x-ms-asf-plugin|\
audio/basic|\
audio/x-au|\
application/x-troff-msvideo|\
video/avi|\
video/msvideo|\
video/x-msvideo|\
application/mac-binary|\
application/macbinary|\
application/x-binary|\
application/x-macbinary|\
image/bmp|\
image/x-windows-bmp|\
application/book|\
text/x-c|\
text/plain|\
application/clariscad|\
application/java|\
application/java-byte-code|\
application/x-java-class|\
application/mac-compactpro|\
application/x-compactpro|\
application/x-cpt|\
application/x-pointplus|\
text/css|\
application/x-director|\
video/x-dv|\
video/dl|\
video/x-dl|\
application/msword|\
application/drafting|\
application/x-dvi|\
application/acad|\
image/vnd.dwg|\
image/x-dwg|\
application/dxf|\
image/gif|\
application/x-compressed|\
application/x-gzip|\
multipart/x-gzip|\
text/x-h|\
application/hlp|\
application/x-helpfile|\
application/x-winhelp|\
text/x-component|\
text/html|\
text/webviewhtml|\
x-conference/x-cooltalk|\
image/x-icon|\
application/inf|\
audio/x-jam|\
text/x-java-source|\
application/x-java-commerce|\
image/jpeg|\
image/pjpeg|\
image/x-jps|\
application/x-javascript|\
application/javascript|\
application/ecmascript|\
text/javascript|\
text/ecmascript|\
application/x-latex|\
application/lha|\
application/x-lha|\
application/x-lisp|\
text/x-script.lisp|\
application/x-lzh|\
application/lzx|\
application/x-lzx|\
audio/x-mpequrl|\
application/x-troff-man|\
application/x-midi|\
audio/midi|\
audio/x-mid|\
audio/x-midi|\
music/crescendo|\
x-music/x-midi|\
audio/mod|\
audio/x-mod|\
video/quicktime|\
video/x-sgi-movie|\
audio/mpeg|\
audio/x-mpeg|\
video/mpeg|\
video/x-mpeg|\
video/x-mpeq2a|\
audio/mpeg3|\
audio/x-mpeg-3|\
video/mp4|\
text/pascal|\
application/vnd.hp-pcl|\
application/x-pcl|\
image/x-pict|\
image/x-pcx|\
application/pdf|\
image/pict|\
text/x-script.perl|\
image/x-xpixmap|\
text/x-script.perl-module|\
application/x-pagemaker|\
image/png|\
application/mspowerpoint|\
application/vnd.ms-powerpoint|\
application/powerpoint|\
application/x-mspowerpoint|\
text/x-script.phyton|\
applicaiton/x-bytecode.python|\
image/x-quicktime|\
audio/x-pn-realaudio|\
audio/x-pn-realaudio-plugin|\
audio/x-realaudio|\
application/vnd.rn-realmedia|\
application/rtf|\
application/x-rtf|\
text/richtext|\
video/vnd.rn-realvideo|\
text/sgml|\
text/x-sgml|\
application/x-bsh|\
application/x-sh|\
application/x-shar|\
text/x-script.sh|\
text/x-server-parsed-html|\
application/x-tar|\
application/x-tcl|\
text/x-script.tcl|\
application/plain|\
application/gnutar|\
image/tiff|\
image/x-tiff|\
text/uri-list|\
application/x-cdlink|\
application/vocaltec-media-desc|\
application/x-vrml|\
model/vrml|\
x-world/x-vrml|\
application/x-visio|\
audio/wav|\
audio/x-wav|\
windows/metafile|\
application/excel|\
application/x-excel|\
application/x-msexcel|\
application/vnd.ms-excel|\
audio/xm|\
application/xml|\
text/xml|\
application/x-compress|\
application/x-zip-compressed|\
application/zip|\
multipart/x-zip)"
#pragma endregion

#pragma region Date time regex definition
#define DATE_TIME \
"([0-9]{4}|\
[0-9]{4}\-[0-9]{2}|\
[0-9]{4}\-[0-9]{2}\-[0-9]{2}|\
[0-9]{4}\-[0-9]{2}\-[0-9]{2}T[0-9]{2}:[0-9]{2}|\
[0-9]{4}\-[0-9]{2}\-[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}|\
[0-9]{4}\-[0-9]{2}\-[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}(\\+|\-)[0-2][0-4]:[0-5][0-9])"
#pragma endregion

#define CHAR_SET            "(iso 646|ISO 646|ascii|ASCII|bcdic||BCDIC|ebcdic|EBCDIC|windows-125[0-8]|WINDOWS-125[0-8]|koi8|KOI8|iscii|ISCII|viscii|VISCII|big5|utf-8|UTF-8|utf-16|UTF-16|utf-32|UTF-32|unicode|UNICODE)"
#define PATH                "^(.*/)?(?:$|(.+?)(?:(\.[^.]*$)|$))" 
#define COLOR               "(#[a-f0-9A-F]{1,6}|aqua|black|blue|fuchsia|gray|green|lime|maroon|navy|olive|purple|red|silver|teal|white|yellow)"
#define SCRIPT              "[a-zA-Z]+:[a-zA-Z][a-zA-Z0-9_]*"
#define INTEGER             "-?[0-9]+"
#define POSITIVE_INTEGER    "[0-9]+"
#define URL                 R"(^(([^:\/?#]+):)?(//([^\/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?)" 
#define IDENTIFIER          "[a-zA-Z][a-zA-Z0-9_]*"         
#define ANY_TEXT            ".+"
#define INTEGER_OR_PERCENT  "[0-9%]+"

#pragma region attribute_values
// В куче атрибутов есть значения по умолчанию, надо видимо как-то учитывать их в классе

// Допридумать:
// 2) Аттрибуты, для которых обязательны кавычки

#define ATTR_ACCESS_KEY_VALS          ("[0-9a-z]"                      )  // +++++ Число от 0 до 9 или маленькая латинская буква
#define ATTR_CLASS_VALS               ("([0-9a-zA-Z-_]+|)"             )  
#define ATTR_CONTENTEDITABLE_VALS     ("(true|false|)"                 )  // +++++ "true" , "false" или пустая строка
#define ATTR_CONTEXTMENU_VALS         ("[a-zA-Z]+"                     )  // !!!!! тут более сложная логика, доделать похже
#define ATTR_DIR_VALS                 ("(ltr|rtl)"                     )  // +++++ "ltr" или "rtl"
#define ATTR_HIDDEN_VALS              ("(hidden|)"                     )  // может вообще быть без строки, надо чекать выше по логике, доделать позже
#define ATTR_ID_VALS                  ("[a-zA-Z][a-zA-Z0-9-_]*"        )  // +++++ Начинается с буквы, дальше буква или цифра или тире или _
#define ATTR_LANG_VALS                LANGUAGE_CODE
#define ATTR_SPELLCHECK_VALS          ("(true|false|)"                 )  // "true" , "false" или пустая строка
#define ATTR_STYLE_VALS               ("[a-zA-Z0-9;: -]+"               )  // CSS syntax
#define ATTR_TABINDEX_VALS            ("[0-9]+"                        )  // positive integer value
#define ATTR_TITLE_VALS               ANY_TEXT
#define ATTR_XMLLANG_VALS             LANGUAGE_CODE                       
#define ATTR_ONBLUR_VARS              SCRIPT
#define ATTR_ONCHANGE_VARS            SCRIPT
#define ATTR_ONCLICK_VALS             SCRIPT
#define ATTR_ONBLCLICK_VALS           SCRIPT
#define ATTR_ONFOCUS_VALS             SCRIPT
#define ATTR_ONKEYDOWN_VALS           SCRIPT
#define ATTR_ONKEYPRESS_VALS          SCRIPT
#define ATTR_ONKEYUP_VALS             SCRIPT
#define ATTR_ONLOAD_VALS              SCRIPT
#define ATTR_ONMOUSEDOWN_VALS         SCRIPT
#define ATTR_ONMOUSEMOVE_VALS         SCRIPT
#define ATTR_ONMOUSEOUT_VALS          SCRIPT
#define ATTR_ONMOUSEOVER_VALS         SCRIPT
#define ATTR_ONMOUSEUP_VALS           SCRIPT
#define ATTR_ONRESET_VALS             SCRIPT
#define ATTR_ONSELECT_VALS            SCRIPT
#define ATTR_ONSUBMIT_VALS            SCRIPT
#define ATTR_ONUNLOAD_VALS            SCRIPT
#define ATTR_ACCEPT_VALS              MIME_TYPE
#define ATTR_ACCEPTCHARSET_VALS       CHAR_SET
#define ATTR_ACTION_VALS              URL 
#define ATTR_ALIGN_VALS               ("(bottom|left|middle|right|top)")  
#define ATTR_ALINK_VALS               COLOR
#define ATTR_ALLOWTRANSPARENCY_VALS   (""                              ) // Значений вообще никаких не должно быть
#define ATTR_ALT_VALS                 ("[a-zA-Z ]+"                    ) // Обязательно должно прийти в двойных кавычках
#define ATTR_ARCHIVE_VALS             PATH                               // Здесь путь или несколько путей должны быть 
#define ATTR_ASYNC_VALS               (""                              ) // Значения вообще не должно быть
#define ATTR_AUTOCOMPLETE_VALS        ("(on|off)"                      )
#define ATTR_AUTOFOCUS_VALS           (""                              ) // Значения вообще не должно быть
#define ATTR_AUTOPLAY_VALS            ("(autoplay|)"                   ) 
#define ATTR_AXIS_VALS                ("[a-zA-Z]*"                     )
#define ATTR_BACKGROUND_VALS          URL
#define ATTR_BALANCE_VALS             ANY_TEXT
#define ATTR_BEHAVIOR_VALS            ("(alternate|scroll|slide|)"     )
#define ATTR_BGCOLOR_VALS             COLOR
#define ATTR_BGPROPERTIES_VALS        ("(fixed|)"                      )
#define ATTR_BORDER_VALS              POSITIVE_INTEGER
#define ATTR_BORDERCOLOR_VALS         COLOR
#define ATTR_BOOTONMARGIN_VALS        ANY_TEXT
#define ATTR_CHALLENGE_VALS           ("[a-zA-Z]*"                     )
#define ATTR_CHAR_VALS                ("[a-zA-Z]"                      ) 
#define ATTR_CHAROFF_VALS             INTEGER
#define ATTR_CHARSET_VALS             CHAR_SET
#define ATTR_CHECKED_VALS             ("(checked|)"                    )
#define ATTR_CELLPADDING_VALS         INTEGER_OR_PERCENT
#define ATTR_CELLSPACING_VALS         POSITIVE_INTEGER
#define ATTR_CITE_VALS                PATH                                // Здесь путь или несколько путей должны быть
#define ATTR_CLASSID_VALS             PATH                                // Здесь путь или несколько путей должны быть
#define ATTR_CLEAR_VALS               ("(all|left|right|none)"         )
#define ATTR_CODE_VALS                ANY_TEXT
#define ATTR_CODEBASE_VALS            PATH
#define ATTR_CODETYPE_VALS            MIME_TYPE 
#define ATTR_CONTENT_VALS             ANY_TEXT
#define ATTR_CONTROLS_VALS            ("(controls|)"                   )
#define ATTR_COLOR_VALS               COLOR
#define ATTR_COLS_VALS                POSITIVE_INTEGER
#define ATTR_CLOSPAN_VALS             POSITIVE_INTEGER
#define ATTR_COORDS_VALS              ("[0-9,]+"                       )  // числа, разделенные запятыми. ПРОВЕРИТЬ
#define ATTR_DATA_VALS                ANY_TEXT
#define ATTR_DATETIME_VALS            DATE_TIME
#define ATTR_DEFAULT_VALS             ("") // без значения
#define ATTR_DEFER_VALS               ("") // без значения
#define ATTR_DIRECTION_VALS           ("(down|left|right|up|)")
#define ATTR_DISABLED_VALS            ("") // без значения
#define ATTR_DOWNLOAD_VALS            ("") // вообще нет и присвоить себе нельзя
#define ATTR_ENCTYPE_VALS             ("(application/x-www-form-urlencoded|multipart/form-data|text/plain|)")
#define ATTR_FACE_VALS                ANY_TEXT
#define ATTR_FRAME_VALS               ("(void|border|above|below|hsides|vsides|rhs|lhs|)")
#define ATTR_FRAMEBORDER_VALS         ("(yes|no|0|1|)")
#define ATTR_FRAMESPACING_VALS        POSITIVE_INTEGER
#define ATTR_FOR_VALS                 IDENTIFIER
#define ATTR_FORM_VALS                IDENTIFIER
#define ATTR_FORMACTION_VALS          URL
#define ATTR_FORMENCTYPE_VALS         ("(application/x-www-form-urlencoded|multipart/form-data|text/plain|)")
#define ATTR_FORMMETHOD_VALS          ("(get|post)")
#define ATTR_FORMOVALIDATE_VALS       ANY_TEXT // не нашел
#define ATTR_FORMTARGET_VALS          ("([a-zA-Z]|_blank|_self|_parent|_top)")
#define ATTR_GUTTER_VALS              ANY_TEXT // не нашел
#define ATTR_HEADERS_VALS             IDENTIFIER  // имя идентификатора, возможно несколько через пробел
#define ATTR_HEIGHT_VALS              POSITIVE_INTEGER
#define ATTR_HREF_VALS                URL
#define ATTR_HREFLANG_VALS            LANGUAGE_CODE
#define ATTR_HSPACE_VALS              POSITIVE_INTEGER
#define ATTR_HTTPEQUIV_VALS           IDENTIFIER
#define ATTR_ICON_VALS                ANY_TEXT // не нашел
#define ATTR_ISMAP_VALS               ("") // нет значения
#define ATTR_KEYTYPE_VALS             IDENTIFIER
#define ATTR_KIND_VALS                IDENTIFIER
#define ATTR_LABEL_VALS               ("[a-zA-Z]*") // кавычки обязательно
#define ATTR_LANGUAGE_VALS            ("(JavaScript|JScript|VBS|VBScript|)")
#define ATTR_LEFTMARGIN_VALS          POSITIVE_INTEGER
#define ATTR_LINK_VALS                COLOR
#define ATTR_LIST_VALS                IDENTIFIER
#define ATTR_LONGDESC_VALS            PATH
#define ATTR_LOOP_VALS                ("(loop|)")
#define ATTR_LOW_VALS                 ("\-?\d+(\.\d{0,})?"             )  // целое или дробное число
#define ATTR_LOWSRC_VALS              PATH 
#define ATTR_MANIFEST_VALS            URL
#define ATTR_MARGINHEIGHT_VALS        POSITIVE_INTEGER
#define ATTR_MARGINWIDTH_VALS         POSITIVE_INTEGER
#define ATTR_MAX_VALS                 POSITIVE_INTEGER
#define ATTR_MAXLEGHT_VALS            POSITIVE_INTEGER
#define ATTR_MEDIA_VALS               ("(all|braille|handheld|print|screen|speech|projection|tty|tv|)")
#define ATTR_METHOD_VALS              ("(get|post|)")
#define ATTR_MIN_VALS                 POSITIVE_INTEGER
#define ATTR_MULTIPLE_VALS            ("") // нет значения
#define ATTR_MUTED_VALS               ("(muted|)")
#define ATTR_NAME_VALS                ("[a-zA-Z]+")
#define ATTR_NOHREF_VALS              ("(nohref|)")
#define ATTR_NORESIZE_VALS            ("(noresize|)")
#define ATTR_NOSHADE_VALS             ("(noshade|)")
#define ATTR_NOVALIDATE_VALS          ("(novalidate|)")
#define ATTR_NOWRAP_VALS              ("(nowrap|)")
#define ATTR_OPEN_VALS                ("") // нет
#define ATTR_OPTIMUM_VALS             ("") // нет
#define ATTR_PATTERN_VALS             ANY_TEXT  // некоторые регулярки из их таблицы   
#define ATTR_PLACEHOLDER_VALS         ANY_TEXT
#define ATTR_PLUGINSPAGE_VALS         URL
#define ATTR_POSTER_VALS              PATH
#define ATTR_PRELOAD_VALS             ("(none|metadata|auto|)")
#define ATTR_PROMPT_VALS              ANY_TEXT
#define ATTR_PUBDATE_VALS             ("") // нет
#define ATTR_RADIOGROUP_VALS          ANY_TEXT  // какой-то там текст  
#define ATTR_READONLY_VALS            ("") // нет
#define ATTR_REL_VALS                 ("(answer|chapter|co-worker|colleague|contact|details|edit|friend|question|archives|author|bookmark|first|help|index|last|license|me|next|nofollow|noreferrer|prefetch|prev|search|sidebar|tag|up)")		      
#define ATTR_REQUIRED_VALS            ("") // нет
#define ATTR_RESERVED_VALS            ("") // нет
#define ATTR_RIGHTMARGIN_VALS         POSITIVE_INTEGER
#define ATTR_ROWS_VALS                ANY_TEXT	      
#define ATTR_ROWSPAN_VALS             POSITIVE_INTEGER     
#define ATTR_RULES_VALS               ("(all|groups|cols|none|rows)")
#define ATTR_SANDBOX_VALS             ("(allow-same-origin|allow-top-navigation|allow-forms|allow-scripts)")
#define ATTR_SCOPE_VALS               ("(col|colgroup|row|rowgroup)")
#define ATTR_SCROLL_VALS              ("(yes|no)")
#define ATTR_SCROLLAMOUNT_VALS        POSITIVE_INTEGER
#define ATTR_SCROLLDELAY_VALS         POSITIVE_INTEGER
#define ATTR_SCROLLING_VALS           ("(auto|no|yes)")
#define ATTR_SHAPE_VALS               ("(circle|default|poly|rect)")
#define ATTR_SEAMLESS_VALS            ("") // нет
#define ATTR_SELECTED_VALS            ("") // нет
#define ATTR_SIZE_VALS                POSITIVE_INTEGER     
#define ATTR_SIZES_VALS               ("([0-9]+x[0-9]+)+")   
#define ATTR_SPAN_VALS                POSITIVE_INTEGER
#define ATTR_SRC_VALS                 PATH
#define ATTR_SRCLANG_VALS             LANGUAGE_CODE       
#define ATTR_SRCDOC_VALS              ANY_TEXT // html код        
#define ATTR_START_VALS               POSITIVE_INTEGER
#define ATTR_STEP_VALS                INTEGER // целое или дробное!!        
#define ATTR_SUMMARY_VALS             ("")  // нет
#define ATTR_TARGET_VALS              ("(_blank|_self|_parent|_top)")
#define ATTR_TEXT_VALS                COLOR
#define ATTR_TOPMARGIN_VALS           POSITIVE_INTEGER
#define ATTR_TRUESPEED_VALS           ("") // нет
#define ATTR_TYPE_VALS                ("(button|checkbox|file|hidden|image|password|radio|reset|submit|text|color|date|datetime|datetime|email|number|range|search|tel|time|url|month|week|text/javascript)")
#define ATTR_USEMAP_VALS              ("#[a-zA-Z]+")
#define ATTR_VALIGN_VALS              ("(top|middle|bottom|baseline)")
#define ATTR_VALUE_VALS               ANY_TEXT
#define ATTR_VALUETYPE_VALS           ("(data|object|ref|)")
#define ATTR_VLINK_VALS               COLOR
#define ATTR_VOLUME_VALS              INTEGER	      
#define ATTR_VSPACE_VALS              INTEGER
#define ATTR_WIDTH_VALS               INTEGER_OR_PERCENT	      
#define ATTR_WRAP_VALS                ("(soft|hard|off|)")
#define ATTR_XMLNS_VALS               URL
#define ATTR_ABBR_VALS                ANY_TEXT
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

static std::map<std::string, std::string> ATTR_DATABASE = ATTR_DATABASE_HTML5;