#pragma once

#include <vector>
#include <string>
#include <map>

#define  ATTR_UNIVERSAL              { "accesskey", "class", "contenteditable", "contextmenu","dir", "hidden", "id", "lang", "spellcheck", "style", "tabindex", "title", "xml:lang" }
#define  ATTR_EVENTS                 { "onblur", "onchange", "onclick", "ondblclick", "onfocus", "onkeydown", "onkeypress", "onkeyup", "onload", "onmousedown", "onmousemove", "onmouseout", "onmouseover", "onmouseup", "onreset","onselect", "onsubmit", "onunload" }
#define  ATTR_UNIVERSAL_AND_EVENTS   { "accesskey", "class", "contenteditable", "contextmenu","dir", "hidden", "id", "lang", "spellcheck", "style", "tabindex", "title", "xml:lang", "onblur", "onchange", "onclick", "ondblclick", "onfocus", "onkeydown", "onkeypress", "onkeyup", "onload", "onmousedown", "onmousemove", "onmouseout", "onmouseover", "onmouseup", "onreset","onselect", "onsubmit", "onunload" }

#define TAG_A_ATTRS                  { "accesskey", "coords", "download", "href", "hreflang", "name", "rel", "shape", "tabindex", "target", "title", "type" }
#define TAG_ABBR_ATTRS               { "title" }
#define TAG_ACRONYM_ATTRS            ATTR_UNIVERSAL_AND_EVENTS
#define TAG_ADDRESS_ATTRS	         ATTR_UNIVERSAL_AND_EVENTS
#define TAG_APPLET_ATTRS    	     {"align", "alt", "archive", "code", "codebase", "height", "hspace", "vspace", "width"}
#define TAG_AREA_ATTRS   		     {"accesskey", "alt", "coords", "href", "hreflang", "nohref", "shape", "tabindex", "target", "type"}
#define	TAG_ARTICLE_ATTRS            {}
#define TAG_ASIDE_ATTRS		         ATTR_UNIVERSAL
#define TAG_AUDIO_ATTRS		         {"autoplay", "controls", "loop","muted", "preload", "src"}
#define TAG_B_ATTRS			         ATTR_UNIVERSAL_AND_EVENTS
#define TAG_BASE_ATTRS		         {"href", "target"}
#define TAG_BASEFONT_ATTRS	         {"color", "face", "size"}
#define TAG_BDI_ATTRS		         ATTR_UNIVERSAL_AND_EVENTS 
#define TAG_BDO_ATTRS		         {"dir"}
#define	TAG_BGSOUND_ATTRS	         {"balance", "loop", "src", "volume"}
#define TAG_BIG_ATTRS		         ATTR_UNIVERSAL_AND_EVENTS 
#define TAG_BLINK_ATTRS              {}
#define TAG_BLOCKQUOTE_ATTRS 	     {"cite"}
#define TAG_BODY_ATTRS   		     {"alink", "background", "bgcolor", "bgcolor", "bgproperties", "bottommargin", "leftmargin", "link", "rightmargin", "scroll", "text", "topmargin", "vlink"}
#define TAG_BR_ATTRS		         {"clear"}
#define TAG_BUTTON_ATTRS    	     {"accesskey", "autofocus", "disabled", "from", "formaction", "formenctype", "formmethod", "formnovalidate", "formtarget", "name", "type", "value"}
#define TAG_CANVAS_ATTRS    	     {"height", "width"}
#define TAG_CAPTION_ATTRS   	     {"align", "valign"}
#define TAG_CENTER_ATTRS             {}
#define TAG_CITE_ATTRS		         ATTR_UNIVERSAL_AND_EVENTS 
#define TAG_CODE_ATTRS		         ATTR_UNIVERSAL_AND_EVENTS 
#define TAG_COL_ATTRS		         {"align", "char", "charoff", "span", "valign", "width"}
#define TAG_COLGROUP_ATTRS	         {"align", "char", "charoff", "span", "valign", "width"}
#define TAG_COMMAND_ATTRS	         {"checked", "disabled", "icon", "label", "radiogroup", "type"}
#define TAG_COMMENT_ATTRS            {}
#define TAG_DATALIST_ATTRS	         {"id"}
#define TAG_DD_ATTRS		         ATTR_UNIVERSAL_AND_EVENTS 
#define TAG_DEL_ATTRS   		     {"cite", "datetime"}
#define TAG_DETAILS_ATTRS	         {"open"}
#define TAG_DFN_ATTRS		         ATTR_UNIVERSAL_AND_EVENTS 
#define TAG_DIR_ATTRS                {}
#define TAG_DIV_ATTRS   		     {"align", "title"}
#define TAG_DL_ATTRS		         ATTR_UNIVERSAL_AND_EVENTS
#define TAG_DT_ATTRS		         ATTR_UNIVERSAL_AND_EVENTS
#define TAG_EM_ATTRS		         ATTR_UNIVERSAL_AND_EVENTS
#define TAG_EMBED_ATTRS		         {"align", "height", "hidden", "hspace", "pluginspage", "src", "type", "vspace", "width"}
#define TAG_FIELDSET_ATTRS   	     {"disabled", "form", "title"}
#define TAG_FIGCAPTION_ATTRS         {}
#define TAG_FIGURE_ATTRS             {}
#define TAG_FONT_ATTRS	       	     {"color", "face", "size"}
#define TAG_FOOTER_ATTRS             {}
#define TAG_FORM_ATTRS   		     {"accept-charset", "action", "autocomplete", "enctype", "method", "name", "novalidate", "target"}
#define TAG_FRAME_ATTRS		         {"bordercolor", "frameborder", "name", "noresize", "scrolling", "src"}
#define TAG_FRAMESET_ATTRS	         {"border", "bordercolor", "cols", "frameborder", "framespacing", "rows"}
#define TAG_H1_ATTRS    		     {"align"}
#define TAG_H2_ATTRS    		     {"align"}
#define TAG_H3_ATTRS     		     {"align"}
#define TAG_H4_ATTRS        	     {"align"}
#define TAG_H5_ATTRS     		     {"align"}
#define TAG_H6_ATTRS    		     {"align"}
#define TAG_HEAD_ATTRS   		     {"profile"}
#define TAG_HEADER_ATTRS             {}
#define TAG_HGROUP_ATTRS             {}
#define TAG_HR_ATTRS    		     {"align", "color", "noshade", "size", "width"}
#define TAG_HTML_ATTRS   		     {"manifest", "title", "xmlns"}
#define TAG_I_ATTRS			         ATTR_UNIVERSAL_AND_EVENTS
#define TAG_IFRAME_ATTRS    	     {"align","allowtransparency","frameborder","height","hspace","marginheight","marginwidth","name","sandbox","scrolling","seamless","src","srcdoc","vspace","width"}
#define TAG_IMG_ATTRS   		     {"align","alt","border","height","hspace","ismap","longdesc","lowsrc","src","usemap","vspace","width"}
#define TAG_INPUT_ATTRS  		     {"accept","accesskey","align","alt","autocomplete","autofocus","border","checked","disabled","form","formaction","formenctype","formmethod","formnovalidate","formtarget","list","max","maxlength","min","multiple","name","pattern","placeholder","readonly","required","size","src","step","tabindex","type","value"}
#define TAG_INS_ATTRS    		     {"cite", "datetime"}
#define TAG_ISINDEX_ATTRS	         {"action", "prompt"}
#define TAG_KBD_ATTRS		         ATTR_UNIVERSAL_AND_EVENTS
#define TAG_KEYGEN_ATTRS	         {"autofocus", "challenge", "disabled", "form", "keytype", "name"}
#define TAG_LABEL_ATTRS		         {"accesskey", "for"}
#define TAG_LEGEND_ATTRS    	     {"accesskey", "align", "title"}
#define TAG_LI_ATTRS    		     {"type", "value"}
#define TAG_LINK_ATTRS   		     {"charset","href","media","rel","sizes","type"}
#define TAG_LISTING_ATTRS            {}
#define TAG_MAIN_ATTRS			     ATTR_UNIVERSAL
#define TAG_MAP_ATTRS			     {"name"}
#define TAG_MARK_ATTRS		         {}	
#define TAG_MARQUEE_ATTRS		     {"behavior","bgcolor","direction","height","hspace","loop","scrollamount","scrolldelay","truespeed","vspace","width"}
#define TAG_MENU_ATTRS			     {"label", "type"}
#define TAG_META_ATTRS			     {"charset","content","http - equiv","name"}
#define TAG_METER_ATTRS			     {"high","low","max","min","optimum","value"}
#define TAG_MULTICOL_ATTRS		     {"cols", "gutter", "width"}
#define TAG_NAV_ATTRS			     {}
#define TAG_NOBR_ATTRS               {}
#define TAG_NOEMBED_ATTRS            {}
#define TAG_NOFRAMES_ATTRS           {}
#define TAG_OBJECT_ATTRS		     {"align","archive","classid","code","codebase","codetype","data","height","hspace","tabindex","type","vspace","width"}
#define TAG_OL_ATTRS    		     {"reserved","start", "type"}
#define TAG_OPTGROUP_ATTRS		     {"disabled", "label"}
#define TAG_OPTION_ATTRS    	     {"disabled","label","selected","value"}
#define TAG_OUTPUT_ATTRS		     {"for", "form", "name"}
#define TAG_P_ATTRS				     {"align"}
#define TAG_PARAM_ATTRS			     {"name","type","value","valuetype"}
#define TAG_PLAINTEXT_ATTRS          {}
#define TAG_PRE_ATTRS	    	     ATTR_UNIVERSAL_AND_EVENTS 	
#define TAG_PROGRESS_ATTRS		     {"value", "max"}
#define TAG_Q_ATTRS				     {"cite"}
#define TAG_RP_ATTRS                 {}
#define TAG_RT_ATTRS                 {}
#define TAG_RUBY_ATTRS               {}
#define TAG_S_ATTRS                  {} 
#define TAG_SAMP_ATTRS	             ATTR_UNIVERSAL_AND_EVENTS 	
#define TAG_SCRIPT_ATTRS		     {"async","defer","language","src","type"}
#define TAG_SECTION_ATTRS	         ATTR_UNIVERSAL_AND_EVENTS 	
#define TAG_SELECT_ATTRS		     {"accesskey","autofocus","disabled","form","multiple","name","required","size","tabindex"}
#define TAG_SMALL_ATTRS			     ATTR_UNIVERSAL_AND_EVENTS 
#define	TAG_SOURCE_ATTRS		     {"media", "src", "type"}
#define TAG_SPACER_ATTRS		     {"align", "height", "size", "type", "width"}
#define TAG_SPAN_ATTRS			     ATTR_UNIVERSAL_AND_EVENTS 
#define TAG_STRIKE_ATTRS		     {}
#define TAG_STRONG_ATTRS		     ATTR_UNIVERSAL_AND_EVENTS 
#define TAG_STYLE_ATTRS			     {"media", "type"}
#define TAG_SUB_ATTRS		         ATTR_UNIVERSAL_AND_EVENTS 		
#define TAG_SUMMARY_ATTRS		     {}
#define TAG_SUP_ATTRS	    	     ATTR_UNIVERSAL_AND_EVENTS 		
#define TAG_TABLE_ATTRS			     {"align","background","bgcolor","border","bordercolor","cellpadding","cellspacing","cols","frame","height","rules","summary","width"}
#define TAG_TBODY_ATTRS  		     {"align","bgcolor","char","charoff","valign"}
#define TAG_TD_ATTRS     		     {"abbr","align","axis","background","bgcolor","bordercolor","char","charoff","colspan","headers","height","nowrap","rowspan","scope","valign","width"}
#define TAG_TEXTAREA_ATTRS  	     {"accesskey","autofocus","cols","disabled","form","maxlength","name","placeholder","readonly","required","rows","tabindex","wrap"}	
#define TAG_TFOOT_ATTRS 		     {"align","bgcolor","char","charoff","valign"}
#define TAG_TH_ATTRS     		     {"abbr","align","axis","background","bgcolor","bordercolor","char","charoff","colspan","headers","height","nowrap","rowspan","scope","valign","width"}
#define TAG_THREAD_ATTRS    	     {"align","bgcolor","char","charoff","valign"}
#define TAG_TIME_ATTRS			     {"datetime", "pubdate"}
#define TAG_TITLE_ATTRS              {}
#define TAG_TR_ATTRS     		     {"align","bgcolor","bordercolor","char","charoff","valign"}
#define TAG_TRACK_ATTRS			     {"kind", "src", "srclang", "label", "default"}
#define TAG_TT_ATTRS                 {}
#define TAG_U_ATTRS		             {}
#define TAG_UL_ATTRS     	         {"type"}
#define TAG_VAR_ATTRS		         ATTR_UNIVERSAL_AND_EVENTS 
#define TAG_VIDEO_ATTRS		         {"autoplay","controls","height","loop","poster","preload","src","width"}
#define TAG_WBR_ATTRS                {}
#define TAG_XMP_ATTRS                {}


// basefront trouble

#define TEST \
{\
    {  "html"               , TAG_HTML_ATTRS       },  \
	{  "a"                  , TAG_A_ATTRS          },  \
	{  "abbr"               , TAG_ABBR_ATTRS       },  \
    { "kek"                 ,  {}                  },  \
	{  "acronym"            , TAG_ACRONYM_ATTRS    },  \
}

/*
#define TAG_DATABASE                                      \
{                                                         \
	{  "a"                  , TAG_A_ATTRS             },  \
	{  "abbr"               , TAG_ABBR_ATTRS          },  \
	{  "acronym"            , TAG_ACRONYM_ATTRS       },  \
	{  "address"            , TAG_ADDRESS_ATTRS       },  \
	{  "applet"             , TAG_APPLET_ATTRS        },  \
	{  "area"               , TAG_AREA_ATTRS          },  \
	{  "article"            , TAG_ARTICLE_ATTRS       },  \
	{  "aside"              , TAG_ASIDE_ATTRS         },  \
	{  "audio"              , TAG_AUDIO_ATTRS         },  \
	{  "b"                  , TAG_B_ATTRS             },  \
	{  "base"               , TAG_BASE_ATTRS          },  \
	{  "basefont"           , TAG_BASEFONT_ATTRS      },  \  
	{  "bdi"                , TAG_BDI_ATTRS           },  \
	{  "bdo"                , TAG_BDO_ATTRS           },  \
	{  "bgsound"            , TAG_BGSOUND_ATTRS       },  \
	{  "big"                , TAG_BIG_ATTRS           },  \
	{  "blink"              , TAG_BLINK_ATTRS         },  \
	{  "blockquote"         , TAG_BLOCKQUOTE_ATTRS    },  \
	{  "body"               , TAG_BODY_ATTRS          },  \
	{  "br"                 , TAG_BR_ATTRS            },  \
	{  "button"             , TAG_BUTTON_ATTRS        },  \
	{  "canvas"             , TAG_CANVAS_ATTRS        },  \
	{  "caption"            , TAG_CAPTION_ATTRS       },  \
	{  "center"             , TAG_CENTER_ATTRS        },  \
	{  "cite"               , TAG_CITE_ATTRS          },  \
	{  "code"               , TAG_CODE_ATTRS          },  \
	{  "col"                , TAG_COL_ATTRS           },  \
	{  "colgroup"           , TAG_COLGROUP_ATTRS      },  \
	{  "command"            , TAG_COMMAND_ATTRS       },  \
	{  "comment"            , TAG_COMMENT_ATTRS       },  \
	{  "datalist"           , TAG_DATALIST_ATTRS      },  \
	{  "dd"                 , TAG_DD_ATTRS            },  \
	{  "del"                , TAG_DEL_ATTRS           },  \
	{  "details"            , TAG_DETAILS_ATTRS       },  \
	{  "dfn"                , TAG_DFN_ATTRS           },  \
	{  "dir"                , TAG_DIR_ATTRS           },  \
	{  "div"                , TAG_DIV_ATTRS           },  \
	{  "dl"                 , TAG_DL_ATTRS            },  \
	{  "dt"                 , TAG_DT_ATTRS            },  \
	{  "em"                 , TAG_EM_ATTRS            },  \
	{  "embed"              , TAG_EMBED_ATTRS         },  \
	{  "fieldset"           , TAG_FIELDSET_ATTRS      },  \
	{  "figcaption"         , TAG_FIGCAPTION_ATTRS    },  \
	{  "figure"             , TAG_FIGURE_ATTRS        },  \
	{  "font"               , TAG_FONT_ATTRS          },  \
	{  "footer"             , TAG_FOOTER_ATTRS        },  \
	{  "form"               , TAG_FORM_ATTRS          },  \
	{  "frame"              , TAG_FRAME_ATTRS         },  \
	{  "frameset"           , TAG_FRAMESET_ATTRS      },  \
	{  "h1"                 , TAG_H1_ATTRS            },  \
	{  "h2"                 , TAG_H2_ATTRS            },  \
	{  "h3"                 , TAG_H3_ATTRS            },  \
	{  "h4"                 , TAG_H4_ATTRS            },  \
	{  "h5"                 , TAG_H5_ATTRS            },  \
	{  "h6"                 , TAG_H6_ATTRS            },  \
	{  "head"               , TAG_HEAD_ATTRS          },  \
	{  "header"             , TAG_HEADER_ATTRS        },  \
	{  "hgroup"             , TAG_HGROUP_ATTRS        },  \
	{  "hr"                 , TAG_HR_ATTRS            },  \
	{  "html"               , TAG_HTML_ATTRS          },  \
	{  "i"                  , TAG_I_ATTRS             },  \
	{  "iframe"             , TAG_IFRAME_ATTRS        },  \
	{  "img"                , TAG_IMG_ATTRS           },  \
	{  "input"              , TAG_INPUT_ATTRS         },  \
	{  "ins"                , TAG_INS_ATTRS           },  \
	{  "isindex"            , TAG_ISINDEX_ATTRS       },  \
	{  "kbd"                , TAG_KBD_ATTRS           },  \
	{  "keygen"             , TAG_KEYGEN_ATTRS        },  \
	{  "label"              , TAG_LABEL_ATTRS         },  \
	{  "legend"             , TAG_LEGEND_ATTRS        },  \
	{  "li"                 , TAG_LI_ATTRS            },  \
	{  "link"               , TAG_LINK_ATTRS          },  \
	{  "listing"            , TAG_LISTING_ATTRS       },  \
	{  "main"               , TAG_MAIN_ATTRS          },  \
	{  "map"                , TAG_MAP_ATTRS           },  \
	{  "mark"               , TAG_MARK_ATTRS          },  \
	{  "marquee"            , TAG_MARQUEE_ATTRS       },  \
	{  "menu"               , TAG_MENU_ATTRS          },  \
	{  "meta"               , TAG_META_ATTRS          },  \
	{  "meter"              , TAG_METER_ATTRS         },  \
	{  "multicol"           , TAG_MULTICOL_ATTRS      },  \
	{  "nav"                , TAG_NAV_ATTRS           },  \
	{  "nobr"               , TAG_NOBR_ATTRS          },  \
	{  "noembed"            , TAG_NOEMBED_ATTRS       },  \
	{  "noframes"           , TAG_NOFRAMES_ATTRS      },  \
	{  "noscript"           , TAG_NOFRAMES_ATTRS      },  \
	{  "object"             , TAG_OBJECT_ATTRS        },  \
	{  "ol"                 , TAG_OL_ATTRS            },  \
	{  "optgroup"           , TAG_OPTGROUP_ATTRS      },  \
	{  "option"             , TAG_OPTION_ATTRS        },  \
	{  "output"             , TAG_OUTPUT_ATTRS        },  \
	{  "p"                  , TAG_P_ATTRS             },  \
	{  "param"              , TAG_PARAM_ATTRS         },  \
	{  "plaintext"          , TAG_PLAINTEXT_ATTRS     },  \
	{  "pre"                , TAG_PRE_ATTRS           },  \
	{  "progress"           , TAG_PROGRESS_ATTRS      },  \
	{  "q"                  , TAG_P_ATTRS             },  \
	{  "rp"                 , TAG_RP_ATTRS            },  \
	{  "rt"                 , TAG_RT_ATTRS            },  \
	{  "ruby"               , TAG_RUBY_ATTRS          },  \
	{  "s"                  , TAG_S_ATTRS             },  \
	{  "samp"               , TAG_SAMP_ATTRS          },  \
	{  "script"             , TAG_SCRIPT_ATTRS        },  \
	{  "section"            , TAG_SECTION_ATTRS       },  \
	{  "select"             , TAG_SELECT_ATTRS        },  \
	{  "small"              , TAG_SMALL_ATTRS         },  \
	{  "source"             , TAG_SOURCE_ATTRS        },  \
	{  "spacer"             , TAG_SPACER_ATTRS        },  \
	{  "span"               , TAG_SPAN_ATTRS          },  \
	{  "strike"             , TAG_STRIKE_ATTRS        },  \
	{  "strong"             , TAG_STRONG_ATTRS        },  \
	{  "style"              , TAG_STYLE_ATTRS         },  \
	{  "sub"                , TAG_SUB_ATTRS           },  \
	{  "summary"            , TAG_SUMMARY_ATTRS       },  \
	{  "sup"                , TAG_SUP_ATTRS           },  \
	{  "table"              , TAG_TABLE_ATTRS         },  \
	{  "tbody"              , TAG_TBODY_ATTRS         },  \
	{  "td"                 , TAG_TD_ATTRS            },  \
	{  "textarea"           , TAG_TEXTAREA_ATTRS      },  \
	{  "tfoot"              , TAG_TFOOT_ATTRS         },  \
	{  "th"                 , TAG_TH_ATTRS            },  \
	{  "thread"             , TAG_THREAD_ATTRS        },  \
	{  "time"               , TAG_TIME_ATTRS          },  \
	{  "title"              , TAG_TITLE_ATTRS         },  \
	{  "tr"                 , TAG_TR_ATTRS            },  \
	{  "track"              , TAG_TRACK_ATTRS         },  \
	{  "tt"                 , TAG_TT_ATTRS            },  \
	{  "u"                  , TAG_U_ATTRS             },  \
	{  "ul"                 , TAG_UL_ATTRS            },  \
	{  "var"                , TAG_VAR_ATTRS           },  \
	{  "video"              , TAG_VIDEO_ATTRS         },  \
	{  "wbr"                , TAG_WBR_ATTRS           },  \
	{  "xmp"                , TAG_XMP_ATTRS           }   \
}
*/

//std::map<std::string, std::vector<std::string>> TagDatabase = TEST;