
function FarenheitToCelsius(und)
	if und then 
		Value = round(((und-32)/1.8), 0.01)
	else
		Value = 0
    end
	return Value
end

function Calculate(und)
	if und then 
	    Value = und
	else
		Value = 1
    end
    SKIN:Bang('!Update')
end

function Update()
    if Value then
	    return Value .. ' - ' .. FarenheitToCelsius(Value)
    else
        return '0'
	end
end

function round(n, mult)
    mult = mult or 1
    return math.floor((n + mult/2)/mult) * mult
end