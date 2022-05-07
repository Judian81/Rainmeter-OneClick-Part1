
function FormatPrice(nVal)

		if tonumber(nVal) then
			priceFormat = comma_value(nVal)	
			return priceFormat
		else
			return ''
		end
end

function comma_value(n) -- credit http://richard.warburton.it
	local left,num,right = string.match(n,'^([^%d]*%d)(%d*)(.-)$')
	return left..(num:reverse():gsub('(%d%d%d)','%1,'):reverse())..right
end

