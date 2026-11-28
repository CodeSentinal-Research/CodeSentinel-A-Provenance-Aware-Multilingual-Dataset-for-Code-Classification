import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        playlist = []
        cur = 0
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "addSong":
                title = tokens[idx+1]
                playlist.append(title)
                idx += 2
            elif cmd == "removeSong":
                title = tokens[idx+1]
                if title in playlist:
                    rem_idx = playlist.index(title)
                    playlist.pop(rem_idx)
                    if cur >= len(playlist): cur = max(0, len(playlist) - 1)
                idx += 2
            elif cmd == "playNext":
                if playlist:
                    cur = (cur + 1) % len(playlist)
                    print(playlist[cur])
                idx += 1
            elif cmd == "playPrevious":
                if playlist:
                    cur = (cur - 1 + len(playlist)) % len(playlist)
                    print(playlist[cur])
                idx += 1
            elif cmd == "moveSong":
                title = tokens[idx+1]
                pos = int(tokens[idx+2])
                if title in playlist:
                    playlist.remove(title)
                    playlist.insert(pos, title)
                idx += 3
            elif cmd == "currentSong":
                print(playlist[cur] if playlist else "")
                idx += 1
if __name__ == '__main__':
    main()