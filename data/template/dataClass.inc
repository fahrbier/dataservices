''+-------------------------------------
''+- Auto-Generated {{ todaysDate }}
''+-------------------------------------

class {{ name }}

{{#properties}}
    ''+-------------------------------------
    ''+- {{ name }}, {{ type }}
    ''+-------------------------------------
    private {{ type }}{{ ccname }}
    public property Get {{ccname}}()
        {{ ccname }} = {{ type }}{{ ccname }}
    end property
    public property Let {{ ccname }} (in{{ ccname }})
        {{ type }}{{ ccname }} = in{{ ccname }}
    end property
{{/properties}}

    public function toJson()
        toJson = "{" _ 
{{#properties}}
                & """{{ name }}"" : """ & escape({{ type }}{{ ccname }}) & """{{^last}}, {{/last}}" _ 
{{/properties}}
                & "}"
    end function
    
    private function escape(inString)
        if len(inString) > 0 then 
            escape = replace(replace(replace(inString,"""","\"""),VBCRLF," "),VBLF," ")
        else
            escape = inString
        end if    
    end function 

end class