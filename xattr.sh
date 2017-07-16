for f in *.*
    xattr -d com.apple.FinderInfo "$f"
end
