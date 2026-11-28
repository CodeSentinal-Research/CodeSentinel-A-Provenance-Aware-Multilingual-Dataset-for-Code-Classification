/**
 * dictionary-seed.js
 * ------------------
 * A frequency-ordered seed dictionary that ships INSIDE the extension so spell
 * checking works instantly on first load with zero network access.
 *
 * The array is ordered roughly by usage frequency (most common first). The
 * dictionary engine uses the index as a frequency score for ranking candidate
 * corrections, so ordering matters. Every correction *target* used elsewhere in
 * the extension is also present here so valid words are never "corrected".
 *
 * To grow this to 100k+ words: drop a newline-separated `src/data/dictionary.txt`
 * (already referenced as a web-accessible resource) and the loader in
 * engine/dictionary.js will merge it in at runtime — still fully offline.
 *
 * PROPER_NOUNS are always capitalized (days, months, countries, languages...).
 */
(function (global) {
  'use strict';

  const GF = (global.GF = global.GF || {});

  // Most-frequent English words + all correction targets. Ordered by frequency.
  const WORDS = (
    'the be to of and a in that have I it for not on with he as you do at ' +
    'this but his by from they we say her she or an will my one all would there ' +
    'their what so up out if about who get which go me when make can like time no ' +
    'just him know take people into year your good some could them see other than ' +
    'then now look only come its over think also back after use two how our work ' +
    'first well way even new want because any these give day most us is am are was ' +
    'were been being has had did does having doing goes went gone saw seen said ' +
    'made making takes took taken gets got gotten comes came running ran run ' +
    'stopped stopping getting putting sitting swimming planning shopping dropping ' +
    'hoping coming beginning writing written wrote friend friends weird receive ' +
    'received receiving tomorrow yesterday today environment environments language ' +
    'languages achieve achieved achieving address addresses restaurant restaurants ' +
    'because before between both business call called car care case center change ' +
    'child children city close company country course create different does during ' +
    'each early world write writes wrong young yes really please thanks thank hello ' +
    'help here home hope hour house however idea important interest interesting keep ' +
    'kind large last late later lead learn leave left less letter life light line ' +
    'list little live local long love machine main man many mark market may mean ' +
    'meet member might mind minute miss money month more morning mother move much ' +
    'music must name near need never night number often old open order part party ' +
    'pass past pay perhaps person place plan play point possible power present ' +
    'probably problem program public put question quite rate reach read ready real ' +
    'reason receive record remember report result return right room run same school ' +
    'science second seem sell send sense service set several should show side since ' +
    'small social something sometimes sound speak special stand start state stay ' +
    'still stop story student study such system table talk teach team tell term test ' +
    'thing though thought three through today together too toward true try turn ' +
    'under understand until upon usually value very view voice wait walk want watch ' +
    'water week whether while white whole why wide wife win window without woman word ' +
    'accommodate apparent argument believe believed calendar category committee ' +
    'completely conscious decision definite definitely disappear disappoint ' +
    'embarrass existence experience familiar finally foreign forty government grammar ' +
    'guard height independent interrupt knowledge library license maintenance ' +
    'manageable necessary noticeable occasion occurred occurrence parallel piece ' +
    'perceive possess possession preferred privilege pronunciation questionnaire ' +
    'recommend referred relevant religious repetition rhythm separate seize similar ' +
    'sincerely successful surprise temperature threshold truly unnecessary usable ' +
    'vacuum vehicle visible weather whether which withdrawal about above across ' +
    'afraid against ago agree ahead almost alone along already although always among ' +
    'amount animal another answer anyone anything appear area around arrive art ask ' +
    'available baby bad ball bank base beautiful bed begin behind believe below best ' +
    'better big bird black blood blue board body book born box boy break bring ' +
    'brother brown build building buy able account act action activity actually add ' +
    'age air allow apply argue arm army attack attention author average avoid away ' +
    'baby bag bar battle beat become beyond bill billion bit board boat born both ' +
    'buy camp cancer candidate capital card cause cell central century certain chair ' +
    'challenge chance character charge check choice choose church citizen civil claim ' +
    'class clear clearly college color common community computer concern condition ' +
    'consider consumer contain continue control cost cover crime cultural culture cup ' +
    'current customer cut dark data daughter dead deal death debate decade decide ' +
    'deep defense degree democratic describe design detail determine develop ' +
    'difference difficult dinner direction discover discuss disease doctor door dream ' +
    'drive drop drug economic economy education effect effort eight either election ' +
    'else employee end energy enjoy enough enter entire environment especially ' +
    'establish evening event ever every everybody everyone everything evidence exactly ' +
    'example executive exist expect experience expert explain eye face fact factor ' +
    'fail fall family far fast father fear federal feel feeling few field fight ' +
    'figure fill film final finally financial find fine finger finish fire firm fish ' +
    'five floor fly focus follow food foot force foreign forget form former forward ' +
    'four free friend front full fund future game garden gas general generation girl ' +
    'glass goal government great green ground group grow growth gun guy hair half ' +
    'hand hang happen happy hard head health hear heart heat heavy history hit hold ' +
    'hospital hot hotel however huge human hundred husband image imagine impact ' +
    'improve include including increase indeed indicate individual industry inside ' +
    'instead institution involve issue item itself job join key kid kill kitchen knew ' +
    'know land language large law lawyer lay learn least leave leg legal level lie ' +
    'likely listen loss lot low majority manage manager material matter maybe meal ' +
    'measure media medical meeting memory mention message method middle military ' +
    'million model modern moment money nation national nature necessary network news ' +
    'newspaper next nice none north note nothing notice occur office officer official ' +
    'oil once operation opportunity option organization outside owner page pain ' +
    'painting paper parent participant particular particularly patient pattern peace ' +
    'per performance period phone physical pick picture piece player pocket police ' +
    'policy political politics poor popular population position positive practice ' +
    'prepare pressure pretty price private process produce product production ' +
    'professional professor property protect prove provide purpose quality quickly ' +
    'race radio raise range rather reality realize receive recent recently recognize ' +
    'reduce reflect region relationship religious remain remove represent republican ' +
    'require research resource respond response responsibility rest reveal rich rise ' +
    'risk road role rule safe save scene score sea season seat section security seek ' +
    'senior series serious serve share short shoot shot shoulder sign significant ' +
    'simple simply single sister site situation size skill skin smile society soldier ' +
    'someone son song soon sort source south space specific spend sport spring staff ' +
    'stage standard star station step stock store street strong structure success ' +
    'suddenly suffer suggest summer support sure surface tax teacher technology ' +
    'television term thousand threat throughout throw thus tonight top total tough ' +
    'trade traditional training travel treat treatment tree trial trip trouble truth ' +
    'type unit various victim visit wall war wear weight west western whatever whom ' +
    'whose wish worker worry writer yard yeah yet nepal monday tuesday wednesday ' +
    'thursday friday saturday sunday january february march april may june july august ' +
    'september october november december ' +
    // British spellings + more everyday vocabulary so real words aren't flagged
    // and near-misses (e.g. favourate->favourite) resolve at distance 1.
    'favourite favourites favorite favorites favour favor favoured colour colours ' +
    'color colors coloured behaviour behavior neighbour neighbours neighbor centre ' +
    'theatre metre litre organise organised organisation realise realised recognise ' +
    'apologise analyse programme catalogue dialogue travelled travelling labelled ' +
    'cancelled jewellery grey tyre defence licence practise honour honours humour ' +
    'labour rumour flavour flavours harbour endeavour splendour vigour ' +
    'always already because before beside besides beyond during except inside outside ' +
    'toward towards underneath within without maybe perhaps really actually probably ' +
    'usually finally simply exactly quickly slowly nearly clearly mostly mainly ' +
    'anyone anybody anything anywhere everyone everybody everything everywhere someone ' +
    'somebody something somewhere nothing nobody nowhere everyday breakfast lunch ' +
    'dinner morning afternoon evening tonight weekend holiday birthday family friend ' +
    'people person student teacher doctor nurse office school college university ' +
    'computer internet website email message phone mobile screen keyboard button ' +
    'water coffee sugar bread butter cheese chicken potato tomato orange apple banana ' +
    'beautiful wonderful amazing awesome terrible horrible difficult easy simple hard ' +
    'happy sad angry tired hungry thirsty excited nervous worried scared surprised ' +
    'question answer problem solution reason result example difference importance ' +
    'money price cost cheap expensive money budget account payment ticket order ' +
    'yesterday tomorrow today weather season summer winter spring autumn ' +
    'important interesting different possible impossible necessary available comfortable'
  ).split(/\s+/).filter(Boolean);

  // Always-capitalized tokens (lowercase key -> canonical capitalized form).
  const PROPER_NOUNS = {
    i: 'I',
    monday: 'Monday', tuesday: 'Tuesday', wednesday: 'Wednesday',
    thursday: 'Thursday', friday: 'Friday', saturday: 'Saturday', sunday: 'Sunday',
    january: 'January', february: 'February', march: 'March', april: 'April',
    june: 'June', july: 'July', august: 'August', september: 'September',
    october: 'October', november: 'November', december: 'December',
    english: 'English', spanish: 'Spanish', french: 'French', german: 'German',
    chinese: 'Chinese', japanese: 'Japanese', hindi: 'Hindi', nepali: 'Nepali',
    america: 'America', american: 'American', england: 'England', britain: 'Britain',
    nepal: 'Nepal', india: 'India', china: 'China', canada: 'Canada',
    australia: 'Australia', europe: 'Europe', africa: 'Africa', asia: 'Asia',
    london: 'London', paris: 'Paris', tokyo: 'Tokyo', kathmandu: 'Kathmandu',
    google: 'Google', chrome: 'Chrome', windows: 'Windows'
  };

  GF.dictionarySeed = { WORDS, PROPER_NOUNS };
})(typeof self !== 'undefined' ? self : this);