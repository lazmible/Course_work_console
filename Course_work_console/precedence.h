#pragma once

#include <vector>
#include <string>
#include <map>

static std::vector<std::string> HeadTagsAllowded = { "base" , "basefont" , "bgsound", "link", "meta", "script", "style", "title" };
static std::map<std::string, std::pair<std::string, bool>> PrecedenceTags =                  
{                                              
  { "area"      , { "map"      , false }   }, 
  { "base"      , { "head"     , false }   }, 
  { "bgsound"   , { "head"     , false }   }, 
  { "button"    , { "form"     , false }   }, 
  { "caption"   , { "table"    , true  }   }, 
  { "colgroup"  , { "table"    , false }   }, 
  { "command"   , { "menu"     , false }   }, 
  { "comment"   , { "body"     , false }   }, 
  { "dd"        , { "dl"       , false }   }, 
  { "dt"        , { "dl"       , false }   }, 
  { "fieldset"  , { "form"     , false }   }, 
  { "figcaption", { "figure"   , true  }   },   
  { "frame"     , { "frameset" , false }   }, 
  { "isindex"   , { "head"     , false }   }, 
  { "keygen"    , { "form"     , false }   }, 
  { "legend"    , { "fieldset" , false }   }, 
  { "li"        , { "ul"       , false }   }, 
  { "link"      , { "head"     , false }   }, 
  { "meta"      , { "head"     , false }   }, 
  { "noframes"  , { "frameset" , false }   }, 
  { "optgroup"  , { "select"   , false }   }, 
  { "option"    , { "select"   , false }   }, 
  { "rp"        , { "ruby"     , false }   }, 
  { "rt"        , { "ruby"     , false }   }, 
  { "source"    , { "audio"    , false }   }, 
  { "style"     , { "head"     , false }   }, 
  { "summary"   , { "details"  , true  }   }, 
  { "tbody"     , { "table"    , false }   }, 
  { "td"        , { "tr"       , false }   }, 
  { "tfoot"     , { "table"    , false }   }, 
  { "th"        , { "tr"       , false }   }, 
  { "thead"     , { "table"    , true  }   }, 
  { "title"     , { "head"     , false }   }, 
  { "tr"        , { "table"    , false }   }  
}
