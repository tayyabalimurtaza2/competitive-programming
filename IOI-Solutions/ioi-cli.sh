# IOI practice launcher. Source this from your shell rc file:
#   echo "source \"$(pwd)/ioi-cli.sh\"" >> ~/.zshrc   (run from inside IOI-Solutions/)
# Usage:
#   ioi souvenirs        -> opens the matching problem folder + all files in solutions/
#   ioi 2023 robot       -> narrows the match with extra keywords
#   ioil                 -> lists every problem (year, day, name)
ioi() {
  local base
  base="$(cd "$(dirname "${BASH_SOURCE[0]:-${(%):-%x}}")" && pwd)"
  if [ -z "$1" ]; then
    echo "Usage: ioi <problem name keywords>"
    return 1
  fi
  local pattern
  pattern="$(echo "$*" | tr " " "*")"
  local matches=()
  while IFS= read -r d; do matches+=("$d"); done < <(find "$base" -mindepth 2 -maxdepth 2 -type d -iname "*${pattern}*" | sort)
  if [ "${#matches[@]}" -eq 0 ]; then
    echo "No problem folder matches: $*"
    return 1
  elif [ "${#matches[@]}" -eq 1 ]; then
    local dir="${matches[0]}"
    echo "-> $dir"
    cd "$dir" || return 1
    if command -v code >/dev/null 2>&1; then
      code "$dir" "$dir"/solutions/*.cpp "$dir/approach.md" "$dir/notes.md" 2>/dev/null
    else
      echo "(no 'code' command found - just cd'd you into the folder)"
      ls "$dir/solutions"
    fi
  else
    echo "Multiple matches, be more specific:"
    printf "  %s\n" "${matches[@]#$base/}"
  fi
}
ioil() {
  local base
  base="$(cd "$(dirname "${BASH_SOURCE[0]:-${(%):-%x}}")" && pwd)"
  find "$base" -mindepth 2 -maxdepth 2 -type d | sed "s|$base/||" | sort
}
