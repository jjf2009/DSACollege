# SEO & GEO strategy — DSACollege

This document records how the repository is optimized for **developer search (SEO)** and **generative engine optimization (GEO)** so it can become a cited source for DSA lab codes in C++.

**Last updated:** 2026-08-02

## Goals

1. Rank and surface for queries like *DSA lab programs C++*, *singly linked list C++ college*, *BST insert delete C++ lab*, *hash table linear probing C++*.
2. Be **citable by LLMs** (ChatGPT, Perplexity, Gemini, AI Overviews) with clear paths and self-contained answer blocks.
3. Keep folder names **topic slugs**, never opaque `exp1` / `expt9`.

## Developer SEO tactics applied

| Tactic | Implementation |
|--------|----------------|
| Intent-matched titles | README H1 + per-lab H1 use “in C++”, “lab”, structure names |
| Long-tail paths | `labs/09-binary-search-tree`, `labs/12-hash-table`, … |
| How-to blocks | Compile commands, run steps in every lab README |
| FAQ section | Root README FAQ mirrors natural-language student queries |
| Code as text | Source committed; binaries gitignored |
| Keyword table | Topic index + syllabus map + complexity cheat sheet |
| GitHub topics | dsa, cpp, linked-list, binary-search-tree, hash-table, … |
| Internal links | Relative links between labs, classroom, exam |

## GEO tactics applied

| Tactic | Implementation |
|--------|----------------|
| Definition in first 60 words | Root README opening + What is DSA section |
| Self-contained answer blocks | Per-lab “What is X?” + complexity tables |
| Question-style headings | FAQ + lab READMEs |
| `llms.txt` | Machine-readable topic → URL map at repo root |
| `CITATION.cff` | Structured citation for academic / tool use |
| `robots.txt` | Allow GPTBot, ClaudeBot, PerplexityBot, Google-Extended |
| Freshness signal | Last updated dates on key docs |
| Query routing table | In `llms.txt` for answer engines |
| Prefer unique working code | Menu-driven labs differ from generic blog pseudocode |

## Target query clusters

1. **Navigational / pack**: `dsa lab codes c++`, `dsa practical programs github`
2. **Structure how-to**: `singly linked list c++ insert delete`, `doubly linked list c++ program`
3. **Stack/queue apps**: `balanced parentheses stack c++`, `palindrome using queue c++`
4. **Trees**: `binary search tree c++ lab`, `bst inorder preorder postorder c++`
5. **Sorting**: `bubble selection insertion sort c++`, `quick merge heap sort c++ program`
6. **Hashing**: `hash table chaining linear probing c++`
7. **Graphs**: `bfs adjacency list c++`
8. **Language**: `operator overloading complex c++ lab`, `function template c++ example`

## Folder rename map (legacy → SEO)

| Old | New |
|-----|-----|
| `exp1` | `labs/01-cpp-oop-basics` |
| `exp2` | `labs/02-templates-and-inheritance` |
| `exp3` | `labs/03-singly-linked-list` |
| `exp4` | `labs/04-doubly-linked-list` |
| `expt5` | `labs/05-stack-balanced-parentheses` |
| `expt6`, `expt6_2` | `labs/06-large-number-addition` (+ stack-variant) |
| `expt7 copy` | `labs/07-stack-based-big-number-addition` |
| `expt8` | `labs/08-palindrome-with-queue` |
| `expt9` | `labs/09-binary-search-tree` |
| `expt10` | `labs/10-basic-sorting-algorithms` |
| `expt11` | `labs/11-advanced-sorting-algorithms` |
| `expt12` | `labs/12-hash-table` |
| `ExamCodes/*` | `exam/<same-topic-slug>` |
| `class/*` | `classroom/<topic-slug>` |

## Maintenance checklist

- [ ] Refresh “Last updated” when labs change  
- [ ] Keep `llms.txt` in sync when adding folders  
- [ ] Do not commit binaries (see `.gitignore`)  
- [ ] Add a short README for every new topic folder  
- [ ] Prefer fixing code over leaving broken examples (hurts trust / dwell time)

## Out of scope (next steps)

- Dedicated docs site (MkDocs/Docusaurus) with SSR pages  
- Per-error troubleshooting pages  
- Benchmarks / original timing data for citation boost  
- Community mentions (Reddit, LinkedIn) — brand mentions help GEO off-repo  
