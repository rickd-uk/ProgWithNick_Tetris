function nvp {
    local files=()
    for arg in "$@"; do
        files+=("*.$arg")
    done
    echo "${files[@]}"
}
